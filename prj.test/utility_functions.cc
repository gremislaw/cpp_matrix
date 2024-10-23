#include "utility_functions.h"

void s21_matrix_utillity::MatrixValidation(const S21Matrix &other,
                                           double value) {
  for (int i = 0; i < other.GetRows(); ++i) {
    for (int j = 0; j < other.GetCols(); ++j) {
      ASSERT_NEAR(other(i, j), value, 1e-7);
    }
  }
}

void s21_matrix_utillity::FillMatrix(S21Matrix &matrix, double value) {
  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      matrix(i, j) = value;
    }
  }
}

void s21_matrix_utillity::TestInverse(const S21Matrix &matrix) {
  S21Matrix matrix_before = matrix;
  double det = matrix.Determinant();
  if (std::abs(det) < 1e-7) {
    EXPECT_ANY_THROW(matrix.InverseMatrix());
  } else {
    S21Matrix matrix_inverse = matrix.InverseMatrix();
    S21Matrix matrix_mult = matrix * matrix_inverse;
    S21Matrix matrix_identity =
        s21_matrix_utillity::GetIdentityMatrix(matrix.GetRows());
    EXPECT_TRUE(matrix_mult == matrix_identity);
  }
  EXPECT_TRUE(matrix == matrix_before);
}

S21Matrix s21_matrix_utillity::GetIdentityMatrix(int size) {
  S21Matrix result{size, size};

  for (int i = 0; i < result.GetRows(); i++) {
    for (int j = 0; j < result.GetCols(); j++) {
      if (i == j) {
        result(i, j) = 1.0;
      }
    }
  }

  return result;
}