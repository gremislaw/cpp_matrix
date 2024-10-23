#include "tests.h"

TEST(TestTranspose, TestTranspose01) {
  S21Matrix matrix1{95, 99};
  EXPECT_EQ(matrix1.GetRows(), 95);
  EXPECT_EQ(matrix1.GetCols(), 99);

  S21Matrix result_check{99, 95};
  EXPECT_EQ(result_check.GetRows(), 99);
  EXPECT_EQ(result_check.GetCols(), 95);

  s21_matrix_utillity::FillMatrix(matrix1, 1.99);
  s21_matrix_utillity::FillMatrix(result_check, 1.99);

  s21_matrix_utillity::MatrixValidation(matrix1, 1.99);
  s21_matrix_utillity::MatrixValidation(result_check, 1.99);

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestTranspose, TestTranspose02) {
  S21Matrix matrix1{99, 95};
  EXPECT_EQ(matrix1.GetRows(), 99);
  EXPECT_EQ(matrix1.GetCols(), 95);

  S21Matrix result_check{95, 99};
  EXPECT_EQ(result_check.GetRows(), 95);
  EXPECT_EQ(result_check.GetCols(), 99);

  s21_matrix_utillity::MatrixValidation(matrix1, 0.0);
  s21_matrix_utillity::MatrixValidation(result_check, 0.0);

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestTranspose, TestTranspose03) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.GetRows(), 99);
  EXPECT_EQ(matrix1.GetCols(), 99);

  S21Matrix result_check{99, 99};
  EXPECT_EQ(result_check.GetRows(), 99);
  EXPECT_EQ(result_check.GetCols(), 99);

  s21_matrix_utillity::FillMatrix(matrix1, -1.5);
  s21_matrix_utillity::FillMatrix(result_check, -1.5);

  s21_matrix_utillity::MatrixValidation(matrix1, -1.5);
  s21_matrix_utillity::MatrixValidation(result_check, -1.5);

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}