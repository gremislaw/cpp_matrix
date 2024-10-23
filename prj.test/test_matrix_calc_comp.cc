#include "tests.h"

TEST(TestCalcComplements, TestCalcComplementsEx01) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsEx02) {
  S21Matrix test_matrix(3, 2);

  EXPECT_EQ(test_matrix.GetRows(), 3);
  EXPECT_EQ(test_matrix.GetCols(), 2);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsEx03) {
  S21Matrix test_matrix(1, 5);

  EXPECT_EQ(test_matrix.GetRows(), 1);
  EXPECT_EQ(test_matrix.GetCols(), 5);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsEx04) {
  S21Matrix test_matrix(5, 1);

  EXPECT_EQ(test_matrix.GetRows(), 5);
  EXPECT_EQ(test_matrix.GetCols(), 1);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}
