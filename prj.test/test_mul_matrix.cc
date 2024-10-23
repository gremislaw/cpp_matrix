#include "tests.h"

TEST(TestMulMatrix, TestMulMatrixFunctionEx01) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionEx02) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionEx03) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionEx04) {
  S21Matrix matrix1{3, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorEx01) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorEx02) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorEx03) {
  S21Matrix matrix1{3, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorEx04) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix01) {
  S21Matrix matrix1{95, 98};
  EXPECT_EQ(matrix1.GetRows(), 95);
  EXPECT_EQ(matrix1.GetCols(), 98);

  S21Matrix matrix2{98, 99};
  EXPECT_EQ(matrix2.GetRows(), 98);
  EXPECT_EQ(matrix2.GetCols(), 99);

  S21Matrix check_matrix{95, 99};
  EXPECT_EQ(check_matrix.GetRows(), 95);
  EXPECT_EQ(check_matrix.GetCols(), 99);

  s21_matrix_utillity::FillMatrix(matrix1, 1.0);
  s21_matrix_utillity::FillMatrix(matrix2, 1.0);
  s21_matrix_utillity::FillMatrix(check_matrix, 98.0);

  S21Matrix matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.GetRows(), 95);
  EXPECT_EQ(matrix1.GetCols(), 99);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix02) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.GetRows(), 99);
  EXPECT_EQ(matrix1.GetCols(), 99);

  S21Matrix matrix2{99, 99};
  EXPECT_EQ(matrix2.GetRows(), 99);
  EXPECT_EQ(matrix2.GetCols(), 99);

  S21Matrix check_matrix{99, 99};
  EXPECT_EQ(check_matrix.GetRows(), 99);
  EXPECT_EQ(check_matrix.GetCols(), 99);

  s21_matrix_utillity::FillMatrix(matrix1, 1.0);
  s21_matrix_utillity::FillMatrix(matrix2, 0.0);
  s21_matrix_utillity::FillMatrix(check_matrix, 0.0);

  S21Matrix matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.GetRows(), 99);
  EXPECT_EQ(matrix1.GetCols(), 99);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperator01) {
  S21Matrix matrix1{95, 98};
  EXPECT_EQ(matrix1.GetRows(), 95);
  EXPECT_EQ(matrix1.GetCols(), 98);

  S21Matrix matrix2{98, 99};
  EXPECT_EQ(matrix2.GetRows(), 98);
  EXPECT_EQ(matrix2.GetCols(), 99);

  S21Matrix check_matrix{95, 99};
  EXPECT_EQ(check_matrix.GetRows(), 95);
  EXPECT_EQ(check_matrix.GetCols(), 99);

  s21_matrix_utillity::FillMatrix(matrix1, 1.0);
  s21_matrix_utillity::FillMatrix(matrix2, 1.0);
  s21_matrix_utillity::FillMatrix(check_matrix, 98.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  S21Matrix result1 = matrix1 * matrix2;
  S21Matrix result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}

TEST(TestMulMatrix, TestMulMatrixOperator02) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.GetRows(), 99);
  EXPECT_EQ(matrix1.GetCols(), 99);

  S21Matrix matrix2{99, 99};
  EXPECT_EQ(matrix2.GetRows(), 99);
  EXPECT_EQ(matrix2.GetCols(), 99);

  S21Matrix check_matrix{99, 99};
  EXPECT_EQ(check_matrix.GetRows(), 99);
  EXPECT_EQ(check_matrix.GetCols(), 99);

  s21_matrix_utillity::FillMatrix(matrix1, 1.0);
  s21_matrix_utillity::FillMatrix(matrix2, 0.0);
  s21_matrix_utillity::FillMatrix(check_matrix, 0.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  S21Matrix result1 = matrix1 * matrix2;
  S21Matrix result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}