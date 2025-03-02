import os
import json
from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class SampleProject(ConanFile):
    name = "sample_project"
    url = ""
    author = "cgg"
    copyright = "Intern"
    description = ""
    homepage = ""
    topics = ("sample_topic")
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = (
        "inc*",
        "src*",
        "CMakeLists.txt",
    )
    options = {
        "build_tests": [True, False],
        "cpptest": [True, False],
        "doxygen": [True, False],
    }
    default_options = {"build_tests": False, "cpptest": False, "doxygen": False}

    def requirements(self):

        self.requires("fmt/10.2.1")
        self.requires("gtest/1.14.0")
        self.requires("cxxopts/3.2.0")
        self.requires("nlohmann_json/3.11.3")
        self.requires("spdlog/1.14.1")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
