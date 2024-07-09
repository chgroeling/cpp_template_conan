#include "sample_lib/sample_lib.h"
#include "sample_lib/internal/internal_class.h"

#include <fmt/core.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>
// #include <spdlog/sinks/null_sink.h>

#include <ctype.h>
#include <spdlog/spdlog.h>

namespace sample_lib {

SampleLib::SampleLib() {
  logger_ = spdlog::get("SampleLib");
  if (!logger_) { // logger was not initialized beforehand
    logger_ = spdlog::stdout_color_mt("SampleLib");
    // Usually it is good to provide a null sink in case no logger was
    // registered by the app
    //
    // logger_ = spdlog::null_logger_mt("BitStream");
  }
};

SampleLib::~SampleLib(){};

Result<void> SampleLib::Execute() {
  internal::InternalClass ic;
  ic.Execute();
  LogTest();
  return Ok();
}

void SampleLib::LogTest() {
  logger_->info("Welcome to spdlog!");
  logger_->error("Some error message with arg: {}", 1);

  logger_->warn("Easy padding in numbers like {:08d}", 12);
  logger_->critical(
      "Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
  logger_->info("Support for floats {:03.2f}", 1.23456);
  logger_->info("Positional args are {1} {0}..", "too", "supported");
  logger_->info("{:<30}", "left aligned");

  logger_->set_level(spdlog::level::debug); // Set global log level to debug
  logger_->debug("This message should be displayed..");
}

void SampleLib::NlohmannJsonTest() {
  // using json = nlohmann::json;
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

} // namespace sample_lib