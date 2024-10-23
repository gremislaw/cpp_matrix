#include "tests.h"

TEST(TestDeterminant, TestDeterminantException01) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException02) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException03) {
  S21Matrix test_matrix(55, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException04) {
  S21Matrix test_matrix(3, 55);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminant1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetCols(), 1);
  EXPECT_EQ(matrix1.GetRows(), 1);

  matrix1(0, 0) = 1.5;

  double result_check = 1.5;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(1, 0) = 1.3;
  matrix1(1, 1) = 1.4;

  double result_check = -0.02;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}