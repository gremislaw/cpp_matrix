#include "tests.h"

TEST(MatrixConstructorSuit, TestException01) {
  EXPECT_ANY_THROW(S21Matrix(-1, 50));
}

TEST(MatrixConstructorSuit, TestException02) {
  EXPECT_ANY_THROW(S21Matrix(0, -50));
}

TEST(MatrixConstructorSuit, TestException03) {
  EXPECT_ANY_THROW(S21Matrix(-40, -50));
}

TEST(MatrixConstructorSuit, TestConstrctorDefault) {
  auto result = S21Matrix();
  EXPECT_EQ(result.GetRows(), 1);
  EXPECT_EQ(result.GetCols(), 1);

  s21_matrix_utillity::MatrixValidation(result, 0.0);
}

TEST(MatrixConstructorSuit, TestConstrctorParams01) {
  S21Matrix result{4, 6};
  EXPECT_EQ(result.GetRows(), 4);
  EXPECT_EQ(result.GetCols(), 6);

  s21_matrix_utillity::MatrixValidation(result, 0.0);
}

TEST(MatrixConstructorSuit, TestConstrctorParams02) {
  S21Matrix result{134, 567};
  EXPECT_EQ(result.GetRows(), 134);
  EXPECT_EQ(result.GetCols(), 567);

  s21_matrix_utillity::MatrixValidation(result, 0.0);
}

TEST(MatrixConstructorSuit, TestConstructorCopy01) {
  S21Matrix result = S21Matrix(2, 2);

  result(0, 0) = 5.0;
  result(0, 1) = 5.0;
  result(1, 0) = 5.0;
  result(1, 1) = 5.0;

  S21Matrix result_copy = result;

  EXPECT_EQ(result.GetCols(), 2);
  EXPECT_EQ(result.GetRows(), 2);

  EXPECT_EQ(result_copy.GetCols(), 2);
  EXPECT_EQ(result_copy.GetRows(), 2);

  s21_matrix_utillity::MatrixValidation(result, 5.0);
  s21_matrix_utillity::MatrixValidation(result_copy, 5.0);
}

TEST(MatrixConstructorSuit, TestConstructorCopy02) {
  S21Matrix result = S21Matrix(2, 2);

  result(0, 0) = 5.0;
  result(0, 1) = 5.0;
  result(1, 0) = 5.0;
  result(1, 1) = 5.0;

  S21Matrix result_copy(result);

  EXPECT_EQ(result.GetCols(), 2);
  EXPECT_EQ(result.GetRows(), 2);

  EXPECT_EQ(result_copy.GetCols(), 2);
  EXPECT_EQ(result_copy.GetRows(), 2);

  s21_matrix_utillity::MatrixValidation(result, 5.0);
  s21_matrix_utillity::MatrixValidation(result_copy, 5.0);
}

TEST(MatrixConstructorSuit, TestConstructorMove01) {
  S21Matrix result{14, 14};
  s21_matrix_utillity::FillMatrix(result, 3.0);

  S21Matrix result_move = std::move(result);

  EXPECT_EQ(result_move.GetCols(), 14);
  EXPECT_EQ(result_move.GetRows(), 14);

  EXPECT_EQ(result.GetCols(), 0);
  EXPECT_EQ(result.GetRows(), 0);

  s21_matrix_utillity::MatrixValidation(result_move, 3.0);
}

TEST(MatrixConstructorSuit, TestConstructorMove02) {
  S21Matrix result = S21Matrix{5, 5};

  EXPECT_EQ(result.GetCols(), 5);
  EXPECT_EQ(result.GetRows(), 5);

  s21_matrix_utillity::MatrixValidation(result, 0.0);
}

TEST(MatrixConstructorSuit, TestAssignmentCopy) {
  S21Matrix result{6, 6};
  S21Matrix result2{3, 3};

  s21_matrix_utillity::FillMatrix(result, 3.0);
  s21_matrix_utillity::FillMatrix(result2, 5.0);

  result2 = result;

  EXPECT_EQ(result.GetCols(), 6);
  EXPECT_EQ(result.GetRows(), 6);
  EXPECT_EQ(result2.GetCols(), 6);
  EXPECT_EQ(result2.GetRows(), 6);

  s21_matrix_utillity::MatrixValidation(result, 3.0);
  s21_matrix_utillity::MatrixValidation(result2, 3.0);
}

TEST(MatrixConstructorSuit, TestAssignmentMove) {
  S21Matrix result{6, 6};
  S21Matrix result2{3, 3};

  s21_matrix_utillity::FillMatrix(result, 3.0);
  s21_matrix_utillity::FillMatrix(result2, 5.0);

  result2 = std::move(result);

  EXPECT_EQ(result.GetCols(), 0);
  EXPECT_EQ(result.GetRows(), 0);
  EXPECT_EQ(result2.GetCols(), 6);
  EXPECT_EQ(result2.GetRows(), 6);

  s21_matrix_utillity::MatrixValidation(result2, 3.0);
}