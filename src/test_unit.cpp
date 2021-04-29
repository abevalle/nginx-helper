#include "gtest.h"

TEST(isValidIp, ipTets) {
    EXPECT_STRNE("10.28.0.1");
    EXPECT_EQ(1);
}