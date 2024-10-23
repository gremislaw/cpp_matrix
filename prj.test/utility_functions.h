#ifndef SRC_TESTS_UTILITY_FUNCTIONS_H_
#define SRC_TESTS_UTILITY_FUNCTIONS_H_

#include "../prj.lab/s21_matrix_oop.h"
#include "tests.h"

namespace s21_matrix_utillity {

void MatrixValidation(const S21Matrix &other, double value);
void FillMatrix(S21Matrix &matrix, double value);
void TestInverse(const S21Matrix &matrix);
S21Matrix GetIdentityMatrix(int size);

} // namespace s21_matrix_utillity

#endif // SRC_TESTS_UTILITY_FUNCTIONS_H_
