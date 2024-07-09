
# Create the library 
set (sample_lib_SOURCES 
  sample_lib/sample_lib.cpp
)


# set(CMAKE_CXX_CPPCHECK "cppcheck")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS FALSE) 

SET (
  COMPILER_WARNING_SWITCHES
  "-Wall"
  "-Wextra"
  "-Wno-comment"
  "-Wno-parentheses"
  "-Wno-format-zero-length"
  "-Wpedantic"
  "-pedantic"
)




add_library(sample_lib ${sample_lib_SOURCES})


target_compile_options(sample_lib
    PRIVATE
    ${COMPILER_WARNING_SWITCHES}
)

# Add the include directories and make them known to other targets (PUBLIC)
target_include_directories(sample_lib PUBLIC ../include PRIVATE ../src)

# Link extern libraries
find_package(fmt REQUIRED)
target_link_libraries(sample_lib PUBLIC fmt::fmt)

find_package(spdlog REQUIRED)
target_link_libraries(sample_lib PUBLIC spdlog::spdlog)

# Link json library
find_package(nlohmann_json REQUIRED)
target_link_libraries(sample_lib PUBLIC nlohmann_json::nlohmann_json)