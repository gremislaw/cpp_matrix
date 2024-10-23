#include "tests.h"

TEST(TestMutators, TestMutatorsException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetRows(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException2) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetRows(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException3) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetCols(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException4) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetCols(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutators1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 1);

  s21_matrix_utillity::FillMatrix(matrix1, 5.5);
  matrix1.SetRows(2);

  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 1);

  EXPECT_NEAR(matrix1(0, 0), 5.5, 1e-7);
  EXPECT_NEAR(matrix1(1, 0), 0.0, 1e-7);
}

TEST(TestMutators, TestMutators2) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 1);

  s21_matrix_utillity::FillMatrix(matrix1, 5.5);
  matrix1.SetCols(2);

  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 2);

  EXPECT_NEAR(matrix1(0, 0), 5.5, 1e-7);
  EXPECT_NEAR(matrix1(0, 1), 0.0, 1e-7);
}

TEST(TestMutators, TestMutators3) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 1);

  s21_matrix_utillity::FillMatrix(matrix1, 5.5);
  matrix1.SetRows(1);

  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 1);

  EXPECT_NEAR(matrix1(0, 0), 5.5, 1e-7);
}

TEST(TestMutators, TestMutators4) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 1);

  s21_matrix_utillity::FillMatrix(matrix1, 5.5);
  matrix1.SetCols(1);

  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 1);

  EXPECT_NEAR(matrix1(0, 0), 5.5, 1e-7);
}