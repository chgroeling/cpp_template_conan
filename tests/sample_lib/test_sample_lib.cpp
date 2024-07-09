#include "sample_lib/sample_lib.h"

#include <gtest/gtest.h>

TEST(TestSampleLib, TestSuccess) {
  sample_lib::SampleLib slib;

  slib.Execute();
  EXPECT_EQ(1000, 1000);
}
