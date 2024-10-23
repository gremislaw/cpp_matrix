#pragma once

#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#define DEFAULT_ROW 1
#define DEFAULT_COL 1

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <utility>

class S21Matrix {
public:
  S21Matrix() noexcept;
  S21Matrix(int row, int columns);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other) noexcept;
  ~S21Matrix() noexcept;
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator=(S21Matrix &&other) noexcept;
  double &operator()(int i, int j) const;

  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  bool EqMatrix(const S21Matrix &other) const noexcept;
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose() const noexcept;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;
  S21Matrix GetMinor(const int row_to_skip, const int col_to_skip) const;

  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix operator*(const double number) const noexcept;
  S21Matrix operator*(const S21Matrix &other) const;
  friend S21Matrix operator*(double number, const S21Matrix &other) noexcept;
  bool operator==(const S21Matrix &other) const;
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const double number);
  S21Matrix &operator*=(const S21Matrix &other);

  void Clear();
  int GetRows() const noexcept;
  int GetCols() const noexcept;
  void SetRows(int new_rows);
  void SetCols(int new_cols);

private:
  int rows_ = 0, cols_ = 0;
  const double eps = 1e-7;
  double **matrix_ = nullptr;
};

#endif