#pragma once

#include <memory>

namespace sample_lib {
namespace internal {

class InternalClass {
public:
  /// Constructor
  InternalClass() = default;

  /// Deconstructor
  virtual ~InternalClass() = default;

  void Execute() {

  };

private:
};

} // namespace internal
} // namespace sample_lib