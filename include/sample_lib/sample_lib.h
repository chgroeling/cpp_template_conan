#pragma once

#include "sample_lib/result.h"
#include "sample_lib/types.h"
#include <memory>

namespace spdlog {
class logger;
}

/// \brief namespace of example library
namespace sample_lib {

/// \brief This is an example class.
/// Go back to \ref mainpage
class SampleLib {
public:
  /// Constructor
  SampleLib();

  /// Deconstructor
  virtual ~SampleLib();

  Result<void> Execute();

private:
  /// Json Test
  void NlohmannJsonTest();

  /// Print outs test logging messages
  void LogTest();

  std::shared_ptr<spdlog::logger> logger_;
};

} // namespace sample_lib