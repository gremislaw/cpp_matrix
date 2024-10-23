#include "tests.h"

TEST(TestSum, TestSumFunctionEx01) {
  S21Matrix result1{2, 2};
  S21Matrix result2{2, 3};

  S21Matrix result1_before = result1;
  S21Matrix result2_before = result2;

  EXPECT_ANY_THROW(result1.SumMatrix(result2));
  EXPECT_ANY_THROW(result2.SumMatrix(result1));
  EXPECT_TRUE(result1 == result1_before);
  EXPECT_TRUE(result2 == result2_before);
}

TEST(TestSum, TestSumFunctionEx02) {
  S21Matrix result1{2, 2};
  S21Matrix result2{3, 2};

  S21Matrix result1_before = result1;
  S21Matrix result2_before = result2;

  EXPECT_ANY_THROW(result1.SumMatrix(result2));
  EXPECT_ANY_THROW(result2.SumMatrix(result1));
  EXPECT_TRUE(result1 == result1_before);
  EXPECT_TRUE(result2 == result2_before);
}

TEST(TestSum, TestSumFunctionEx03) {
  S21Matrix result1{3, 2};
  S21Matrix result2{2, 2};

  S21Matrix result1_before = result1;
  S21Matrix result2_before = result2;

  EXPECT_ANY_THROW(result1.SumMatrix(result2));
  EXPECT_ANY_THROW(result2.SumMatrix(result1));
  EXPECT_TRUE(result1 == result1_before);
  EXPECT_TRUE(result2 == result2_before);
}

TEST(TestSum, TestSumFunctionEx04) {
  S21Matrix result1{2, 3};
  S21Matrix result2{2, 2};

  S21Matrix result1_before = result1;
  S21Matrix result2_before = result2;

  EXPECT_ANY_THROW(result1.SumMatrix(result2));
  EXPECT_ANY_THROW(result2.SumMatrix(result1));
  EXPECT_TRUE(result1 == result1_before);
  EXPECT_TRUE(result2 == result2_before);
}

TEST(TestSum, TestSumOperatorEx01) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorEx02) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorEx03) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorEx04) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSum01) {
  S21Matrix matrix1{35, 99};
  EXPECT_EQ(matrix1.GetRows(), 35);
  EXPECT_EQ(matrix1.GetCols(), 99);

  S21Matrix matrix2{35, 99};
  EXPECT_EQ(matrix2.GetRows(), 35);
  EXPECT_EQ(matrix2.GetCols(), 99);

  s21_matrix_utillity::FillMatrix(matrix1, 2.5);
  s21_matrix_utillity::FillMatrix(matrix2, -2.5);

  matrix1.SumMatrix(matrix2);

  s21_matrix_utillity::MatrixValidation(matrix1, 0.0);

  matrix2.SumMatrix(matrix1);

  s21_matrix_utillity::MatrixValidation(matrix2, -2.5);
}

TEST(TestSum, TestSumOperation01) {
  S21Matrix matrix1{35, 99};
  EXPECT_EQ(matrix1.GetRows(), 35);
  EXPECT_EQ(matrix1.GetCols(), 99);

  S21Matrix matrix2{35, 99};
  EXPECT_EQ(matrix2.GetRows(), 35);
  EXPECT_EQ(matrix2.GetCols(), 99);

  s21_matrix_utillity::FillMatrix(matrix1, 2.5);
  s21_matrix_utillity::FillMatrix(matrix2, -2.5);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1 + matrix2;

  EXPECT_EQ(result.GetRows(), 35);
  EXPECT_EQ(result.GetCols(), 99);
  s21_matrix_utillity::MatrixValidation(result, 0.0);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumOperation02) {
  S21Matrix matrix1{95, 99};
  EXPECT_EQ(matrix1.GetRows(), 95);
  EXPECT_EQ(matrix1.GetCols(), 99);

  S21Matrix matrix2{95, 99};
  EXPECT_EQ(matrix2.GetRows(), 95);
  EXPECT_EQ(matrix2.GetCols(), 99);

  s21_matrix_utillity::FillMatrix(matrix1, 2.5);
  s21_matrix_utillity::FillMatrix(matrix2, 3.5);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result{95, 99};

  result += matrix1;

  EXPECT_EQ(result.GetRows(), 95);
  EXPECT_EQ(result.GetCols(), 99);
  s21_matrix_utillity::MatrixValidation(result, 2.5);

  result += matrix2;

  EXPECT_EQ(result.GetRows(), 95);
  EXPECT_EQ(result.GetCols(), 99);
  s21_matrix_utillity::MatrixValidation(result, 2.5 + 3.5);

  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}