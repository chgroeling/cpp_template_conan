# C++ Template Conan Project

## Overview
This project is a template for a C++ project using Conan for dependency management and CMake as the build system. It provides a preconfigured development environment for easy use.

## Requirements
- C++ compiler (e.g., GCC, Clang, MSVC)
- CMake (minimum version 3.16)
- Conan (minimum version 2.0)
- Python (if managing Conan with Python)

## Installation
1. **Prepare Conan environment using the provided profiles**
   ```sh
   conan profile detect
   conan install . --pr=./profiles/<insert-profile> --output-folder=build --build=missing
   ```

2. **Build the project**
   ```sh
   cmake -B build
   cmake --build build
   ```

3. **Run the application**
   ```sh
   ./build/main
   ```

## Project Structure
```
cpp_template_conan/
├── CMakeLists.txt        # Main CMake configuration file
├── conanfile.py          # Conan package management
├── profiles/             # Conan profiles for different configurations
├── src/                  # Source code directory
├── include/              # Header files
├── tests/                # Unit tests
├── .gitignore            # Git ignore file
├── README.txt            # This file
└── build/                # Build output (not versioned)
```

## Development Guidelines
- **Code Formatting:** `.clang-format` defines the coding style.
- **Dependencies:** All external libraries are managed through Conan.
- **Tests:** Tests are located in the `tests/` directory and should be written using Google Test.

## License
This project is licensed under the MIT License. See `LICENSE` for details.

