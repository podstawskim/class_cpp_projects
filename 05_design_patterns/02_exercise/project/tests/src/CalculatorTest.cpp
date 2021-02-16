#include "Calculator.h"
#include <gtest/gtest.h>

TEST(Calculator, Add) {

    Calculator calculator{1, 2};
    EXPECT_EQ(3, calculator.add());
}
