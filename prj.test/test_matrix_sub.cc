#include "tests.h"

TEST(TestSub, TestSubFunctionEx01) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubFunctionEx02) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubFunctionEx03) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubFunctionEx04) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorEx01) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorEx02) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorEx03) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorEx04) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSub01) {
  S21Matrix matrix1{95, 99};
  EXPECT_EQ(matrix1.GetRows(), 95);
  EXPECT_EQ(matrix1.GetCols(), 99);

  S21Matrix matrix2{95, 99};
  EXPECT_EQ(matrix2.GetRows(), 95);
  EXPECT_EQ(matrix2.GetCols(), 99);

  s21_matrix_utillity::FillMatrix(matrix1, 2.5);
  s21_matrix_utillity::FillMatrix(matrix2, 3.5);

  matrix1.SubMatrix(matrix2);

  s21_matrix_utillity::MatrixValidation(matrix1, -1.0);

  matrix2.SubMatrix(matrix1);

  s21_matrix_utillity::MatrixValidation(matrix2, 4.5);
}

TEST(TestSub, TestSub02) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.GetRows(), 99);
  EXPECT_EQ(matrix1.GetCols(), 99);

  S21Matrix matrix2{99, 99};
  EXPECT_EQ(matrix2.GetRows(), 99);
  EXPECT_EQ(matrix2.GetCols(), 99);

  s21_matrix_utillity::FillMatrix(matrix1, 2.5);
  s21_matrix_utillity::FillMatrix(matrix2, 3.5);

  matrix1.SubMatrix(matrix2);

  s21_matrix_utillity::MatrixValidation(matrix1, -1.0);

  matrix2.SubMatrix(matrix1);

  s21_matrix_utillity::MatrixValidation(matrix2, 4.5);
}

TEST(TestSub, TestSubOperation01) {
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
  S21Matrix result = matrix1 - matrix2;

  EXPECT_EQ(result.GetRows(), 95);
  EXPECT_EQ(result.GetCols(), 99);
  s21_matrix_utillity::MatrixValidation(result, -1.0);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation02) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.GetRows(), 99);
  EXPECT_EQ(matrix1.GetCols(), 99);

  S21Matrix matrix2{99, 99};
  EXPECT_EQ(matrix2.GetRows(), 99);
  EXPECT_EQ(matrix2.GetCols(), 99);

  s21_matrix_utillity::FillMatrix(matrix1, 2.5);
  s21_matrix_utillity::FillMatrix(matrix2, 4.5);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1 - matrix2;

  EXPECT_EQ(result.GetRows(), 99);
  EXPECT_EQ(result.GetCols(), 99);
  s21_matrix_utillity::MatrixValidation(result, -2.0);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation03) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.GetRows(), 99);
  EXPECT_EQ(matrix1.GetCols(), 99);

  S21Matrix matrix2{99, 99};
  EXPECT_EQ(matrix2.GetRows(), 99);
  EXPECT_EQ(matrix2.GetCols(), 99);

  s21_matrix_utillity::FillMatrix(matrix1, 2.5);
  s21_matrix_utillity::FillMatrix(matrix2, -3.5);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result{99, 99};

  result -= matrix1;

  EXPECT_EQ(result.GetRows(), 99);
  EXPECT_EQ(result.GetCols(), 99);
  s21_matrix_utillity::MatrixValidation(result, -2.5);

  result -= matrix2;

  EXPECT_EQ(result.GetRows(), 99);
  EXPECT_EQ(result.GetCols(), 99);
  s21_matrix_utillity::MatrixValidation(result, 1.0);

  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}
