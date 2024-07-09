#include <cxxopts.hpp>
#include <fmt/core.h>
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

#include "sample_lib/sample_lib.h"

using json = nlohmann::json;

void NlohmannJsonTest() {
  auto j = R"(
    {
      "happy": true,
      "pi": 3.141
    }
  )"_json;

  // serialization with pretty printing
  // pass in the amount of spaces to indent
  std::cout << j.dump(4) << std::endl;
}

void LogTest() {
  spdlog::info("Welcome to spdlog!");
  spdlog::error("Some error message with arg: {}", 1);

  spdlog::warn("Easy padding in numbers like {:08d}", 12);
  spdlog::critical(
      "Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
  spdlog::info("Support for floats {:03.2f}", 1.23456);
  spdlog::info("Positional args are {1} {0}..", "too", "supported");
  spdlog::info("{:<30}", "left aligned");

  spdlog::set_level(spdlog::level::debug); // Set global log level to debug
  spdlog::debug("This message should be displayed..");
}

int ParseCommandLine(int argc, const char **argv) {
  cxxopts::Options options("SampleApp",
                           "One line description of \"sample_app\"");

  options.positional_help("<filenames>");

  // clang-format off
  options.add_options()
    ("l,filelist", "Print out file list to be read") // a bool parameter
    ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))
    ("h,help", "Print usage")
    ("input_files", "Input file(s) to concatenate",cxxopts::value<std::vector<std::string>>())
    ;
  // clang-format on

  // parse positional arguments into vector filenames
  options.parse_positional({"input_files"});

  cxxopts::ParseResult result;
  result = options.parse(argc, argv);

  // print out help if necessary
  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    return EXIT_SUCCESS;
  }

  // Enable logging
  switch (result.count("verbose")) {
  case 0:
    // no output
    break;
  case 1:
    std::cout << "verbose:1\n";
    break;
  case 2:
    std::cout << "verbose:2\n";
    break;
  default:
    std::cout << "verbose:?\n";
    break;
  }

  if (result.count("filelist")) {
    std::cout << "filelist command \n";
    const auto files = result["input_files"].as<std::vector<std::string>>();
    for (const auto &file : files) {
      std::cout << "- " << file << "\n";
    }
  }
  return EXIT_SUCCESS;
}

int main(int argc, const char *argv[]) {
  int ret = EXIT_SUCCESS;

  // Test logging library
  LogTest();

  // Nlohmanns json lib test
  NlohmannJsonTest();

  // Test local library
  sample_lib::SampleLib lib;
  lib.Execute();

  // Parse command line options
  ret = ParseCommandLine(argc, argv);

  return ret;
}
