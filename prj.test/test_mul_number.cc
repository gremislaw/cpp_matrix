#include "tests.h"

TEST(TestMulNumber, TestMulNumber01) {
  S21Matrix matrix1{95, 99};
  EXPECT_EQ(matrix1.GetRows(), 95);
  EXPECT_EQ(matrix1.GetCols(), 99);

  double number = 2.0;

  s21_matrix_utillity::FillMatrix(matrix1, 2.5);

  matrix1.MulNumber(number);

  s21_matrix_utillity::MatrixValidation(matrix1, 2.5 * number);

  matrix1.MulNumber(number);

  s21_matrix_utillity::MatrixValidation(matrix1, 2.5 * number * number);
}

TEST(TestMulNumber, TestMulNumber02) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.GetRows(), 99);
  EXPECT_EQ(matrix1.GetCols(), 99);

  double number = -2.5;

  s21_matrix_utillity::FillMatrix(matrix1, 2.5);

  matrix1.MulNumber(number);

  s21_matrix_utillity::MatrixValidation(matrix1, 2.5 * number);

  matrix1.MulNumber(number);

  s21_matrix_utillity::MatrixValidation(matrix1, 2.5 * number * number);
}

TEST(TestMulNumber, TestMulNumber03) {
  S21Matrix matrix1{199, 1};
  EXPECT_EQ(matrix1.GetRows(), 199);
  EXPECT_EQ(matrix1.GetCols(), 1);

  double number = -2.999;

  s21_matrix_utillity::FillMatrix(matrix1, -1.999);

  matrix1.MulNumber(number);

  s21_matrix_utillity::MatrixValidation(matrix1, -1.999 * number);

  matrix1.MulNumber(number);

  s21_matrix_utillity::MatrixValidation(matrix1, -1.999 * number * number);
}

TEST(TestMulNumber, TestMulNumber04) {
  S21Matrix matrix1{1, 199};
  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 199);

  double number = 2.5999;

  s21_matrix_utillity::FillMatrix(matrix1, 1.5999);

  matrix1.MulNumber(number);

  s21_matrix_utillity::MatrixValidation(matrix1, 1.5999 * number);

  matrix1.MulNumber(number);

  s21_matrix_utillity::MatrixValidation(matrix1, 1.5999 * number * number);
}

TEST(TestMulNumber, TestMulNumberOperator01) {
  S21Matrix matrix1{95, 99};
  EXPECT_EQ(matrix1.GetRows(), 95);
  EXPECT_EQ(matrix1.GetCols(), 99);

  double number = 2.0;

  s21_matrix_utillity::FillMatrix(matrix1, 2.5);
  S21Matrix matrix1_before = matrix1;
  S21Matrix result1 = matrix1 * number;
  S21Matrix result2 = number * matrix1;
  S21Matrix result3 = matrix1;
  result3 *= number;

  s21_matrix_utillity::MatrixValidation(result1, 2.5 * number);
  s21_matrix_utillity::MatrixValidation(result2, 2.5 * number);
  s21_matrix_utillity::MatrixValidation(result3, 2.5 * number);
  EXPECT_TRUE(matrix1_before == matrix1);
}

TEST(TestMulNumber, TestMulNumberOperator02) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.GetRows(), 99);
  EXPECT_EQ(matrix1.GetCols(), 99);

  double number = -2.5;

  s21_matrix_utillity::FillMatrix(matrix1, 2.5);
  S21Matrix matrix1_before = matrix1;
  S21Matrix result1 = matrix1 * number;
  S21Matrix result2 = number * matrix1;
  S21Matrix result3 = matrix1;
  result3 *= number;

  s21_matrix_utillity::MatrixValidation(result1, 2.5 * number);
  s21_matrix_utillity::MatrixValidation(result2, 2.5 * number);
  s21_matrix_utillity::MatrixValidation(result3, 2.5 * number);
  EXPECT_TRUE(matrix1_before == matrix1);
}

TEST(TestMulNumber, TestMulNumberOperator03) {
  S21Matrix matrix1{199, 1};
  EXPECT_EQ(matrix1.GetRows(), 199);
  EXPECT_EQ(matrix1.GetCols(), 1);

  double number = -2.999;

  s21_matrix_utillity::FillMatrix(matrix1, -1.999);
  S21Matrix matrix1_before = matrix1;
  S21Matrix result1 = matrix1 * number;
  S21Matrix result2 = number * matrix1;
  S21Matrix result3 = matrix1;
  result3 *= number;

  s21_matrix_utillity::MatrixValidation(result1, -1.999 * number);
  s21_matrix_utillity::MatrixValidation(result2, -1.999 * number);
  s21_matrix_utillity::MatrixValidation(result3, -1.999 * number);
  EXPECT_TRUE(matrix1_before == matrix1);
}

TEST(TestMulNumber, TestMulNumberOperator04) {
  S21Matrix matrix1{1, 199};
  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 199);

  double number = 2.5999;

  s21_matrix_utillity::FillMatrix(matrix1, 1.5999);
  S21Matrix matrix1_before = matrix1;
  S21Matrix result1 = matrix1 * number;
  S21Matrix result2 = number * matrix1;
  S21Matrix result3 = matrix1;
  result3 *= number;

  s21_matrix_utillity::MatrixValidation(result1, 1.5999 * number);
  s21_matrix_utillity::MatrixValidation(result2, 1.5999 * number);
  s21_matrix_utillity::MatrixValidation(result3, 1.5999 * number);
  EXPECT_TRUE(matrix1_before == matrix1);
}
