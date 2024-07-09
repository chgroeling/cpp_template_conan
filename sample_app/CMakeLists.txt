set(APP_SOURCES
  main.cpp
)

add_executable(sample_app ${APP_SOURCES})

# Link local libraries
target_link_libraries(sample_app PUBLIC sample_lib)

# Link string format library
find_package(fmt REQUIRED)
target_link_libraries(sample_app PUBLIC fmt::fmt)

# Link logging library
find_package(spdlog REQUIRED)
target_link_libraries(sample_app PUBLIC spdlog::spdlog)


# Link command line option library
find_package(cxxopts REQUIRED)
target_link_libraries(sample_app PUBLIC cxxopts::cxxopts)

# Link json library
find_package(nlohmann_json REQUIRED)
target_link_libraries(sample_app PUBLIC nlohmann_json::nlohmann_json)

