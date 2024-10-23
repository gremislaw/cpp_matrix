#include "tests.h"

TEST(TestInverse, TestInverseException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseException2) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseException3) {
  S21Matrix test_matrix(1, 5);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseException4) {
  S21Matrix test_matrix(5, 1);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseZero1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetCols(), 1);
  EXPECT_EQ(matrix1.GetRows(), 1);

  matrix1(0, 0) = 0.0;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}
