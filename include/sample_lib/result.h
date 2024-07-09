#pragma once

namespace sample_lib {
enum class StatusCode {
  // clang-format off

  kScSuccess = 0, // Operation succedded successfully 
  kScError = 1, // An unspecified error occured
  kScOutOfRange = 2,
  kScInaccesibleMemoryRegion =4, 
  kScIteratorExhausted = 5,
  kScUnknownOpCode = 6,
  kScUnknownRegister = 7,
  kScUnpredictable = 8, // see Armv7-M Architecture Reference Manual Issue E.e p.818
  kScUndefined = 9,
  kScWriteNotAllowed = 10,

  // clang-format on
};

static const char *StatusCodeToString(const StatusCode &status_code) {
  switch (status_code) {
  case StatusCode::kScSuccess: {
    return "Success";
  }
  case StatusCode::kScError: {
    return "Error";
  }
  case StatusCode::kScOutOfRange: {
    return "OutOfRange";
  }
  case StatusCode::kScInaccesibleMemoryRegion: {
    return "InaccesibleMemoryRegion";
  }
  case StatusCode::kScIteratorExhausted: {
    return "IteratorExhausted";
  }
  case StatusCode::kScUnknownOpCode: {
    return "UnknownOpCode";
  }
  case StatusCode::kScUnknownRegister: {
    return "UnknownRegister";
  }
  case StatusCode::kScUnpredictable: {
    return "Unpredictable";
  }
  case StatusCode::kScWriteNotAllowed: {
    return "WriteNotAllowed";
  }
  case StatusCode::kScUndefined: {
    return "Undefined";
  }
  }
  return "UnknownStatusCode";
}

template <typename T> struct Result {
  const StatusCode status_code;
  const T content;

  inline bool is_ok() const { return status_code == StatusCode::kScSuccess; }
  inline bool is_err() const { return status_code != StatusCode::kScSuccess; }

  bool operator==(Result<T> const &rhs) const {
    return (rhs.status_code == this->status_code) &&
           (rhs.content == this->content);
  }

  const char *ToString() const { return StatusCodeToString(status_code); }
};

template <> struct Result<void> {
  const StatusCode status_code;

  inline bool is_ok() const { return status_code == StatusCode::kScSuccess; }
  inline bool is_err() const { return status_code != StatusCode::kScSuccess; }

  bool operator==(Result<void> const &rhs) const {
    return (rhs.status_code == this->status_code);
  }

  const char *ToString() const { return StatusCodeToString(status_code); }
};

// convience function
template <typename T> static inline Result<T> Ok(T content) {
  return Result<T>{StatusCode::kScSuccess, content};
}
static inline Result<void> Ok() { return Result<void>{StatusCode::kScSuccess}; }

// convience function
template <typename T>
static inline Result<T> Err(StatusCode sc, T content = T()) {
  return Result<T>{sc, content};
}

static inline Result<void> Err(StatusCode sc) { return Result<void>{sc}; }

template <typename T, typename U>
static inline Result<T> Err(Result<U> res, T content = T()) {
  return Result<T>{res.status_code, content};
}

template <typename U> static inline Result<void> Err(Result<U> res) {
  return Result<void>{res.status_code};
}

} // namespace sample_lib