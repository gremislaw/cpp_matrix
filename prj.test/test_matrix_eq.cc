#include "tests.h"

TEST(EqTest, Case01) {
  S21Matrix result1{1, 1};
  S21Matrix result2{1, 1};

  result1(0, 0) = -15;
  result2(0, 0) = 17;

  EXPECT_FALSE(result1 == result2);
}

TEST(EqTest, Case02) {
  S21Matrix result1{2, 2};
  EXPECT_EQ(result1.GetCols(), 2);
  EXPECT_EQ(result1.GetRows(), 2);

  S21Matrix result2{2, 2};
  EXPECT_EQ(result2.GetCols(), 2);
  EXPECT_EQ(result2.GetRows(), 2);

  EXPECT_TRUE(result1.EqMatrix(result2));
  EXPECT_TRUE(result1 == result2);

  result1(0, 0) = -15;
  result2(0, 0) = -15;

  EXPECT_TRUE(result1.EqMatrix(result2));
  EXPECT_TRUE(result1 == result2);
}