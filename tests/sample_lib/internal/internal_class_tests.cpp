#include "sample_lib/internal/internal_class.h"

#include <gtest/gtest.h>

TEST(TestInternalClass, TestSuccess) {
  sample_lib::internal::InternalClass iclass;
  iclass.Execute();
  EXPECT_EQ(1000, 1000);
}
