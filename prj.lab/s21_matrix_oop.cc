#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept : S21Matrix(DEFAULT_ROW, DEFAULT_COL) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw std::length_error("error, size must be greater or equal 0");
  }
  matrix_ = new double *[rows_];
  for (int row = 0; row < rows_; row++) {
    try {
      matrix_[row] = new double[cols_]{};
    } catch (...) {
      for (int i = 0; i < row; ++i) {
        delete[] matrix_[i];
      }
      delete[] matrix_;
      throw;
    }
  }
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      (*this)(row, col) = other(row, col);
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() noexcept { Clear(); }

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    S21Matrix tmp{other};
    *this = std::move(tmp);
  }
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this != &other) {
    Clear();
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }
  return *this;
}

double &S21Matrix::operator()(int i, int j) const {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_)
    throw std::out_of_range("matrix index out of range");
  return matrix_[i][j];
}

void S21Matrix::Clear() {
  if (matrix_ != nullptr) {
    for (int row = 0; row < rows_; row++) {
      delete matrix_[row];
    }
    delete matrix_;
  }
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

bool S21Matrix::EqMatrix(const S21Matrix &other) const noexcept {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (std::abs(other(i, j) - (*this)(i, j)) > eps) {
        return false;
      }
    }
  }

  return true;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (cols_ != other.cols_ || rows_ != other.rows_)
    throw std::logic_error("matrix sizes are not equal");
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      (*this)(row, col) += other(row, col);
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (cols_ != other.cols_ || rows_ != other.rows_)
    throw std::logic_error("matrix sizes are not equal");
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      (*this)(row, col) -= other(row, col);
    }
  }
}

void S21Matrix::MulNumber(const double value) noexcept {
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      (*this)(row, col) *= value;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_)
    throw std::logic_error("incorrect matrix sizes for mul");
  S21Matrix result{rows_, other.cols_};

  for (int row = 0; row < result.rows_; row++) {
    for (int col = 0; col < result.cols_; col++) {
      for (int el = 0; el < cols_; el++) {
        result(row, col) += (*this)(row, el) * other(el, col);
      }
    }
  }
  *this = std::move(result);
}

S21Matrix S21Matrix::Transpose() const noexcept {
  S21Matrix result(cols_, rows_);
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      result(col, row) = (*this)(row, col);
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_)
    throw std::logic_error("incorrect matrix size for CalcComplements");

  S21Matrix result{rows_, cols_};
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      result(row, col) = pow(-1, row + col) * GetMinor(row, col).Determinant();
    }
  }
  return result;
}

double S21Matrix::Determinant() const {
  if (rows_ != cols_)
    throw std::logic_error("Incorrect matrix size for Determinant");
  double determ = 0;
  if (rows_ == 1) {
    determ = (*this)(0, 0);
  } else if (rows_ == 2) {
    determ = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    int sign = 1;
    for (int i = 0; i < cols_; i++) {
      determ += (*this)(0, i) * GetMinor(0, i).Determinant() * sign;
      sign = -sign;
    }
  }
  return determ;
}

S21Matrix S21Matrix::InverseMatrix() const {
  double determ = Determinant();
  if (std::abs(determ) < eps) {
    throw std::logic_error("Determinant must be non-zero to calculate Inverse");
  }
  return Transpose().CalcComplements() * (1.0 / determ);
}

S21Matrix S21Matrix::GetMinor(const int row_to_skip,
                              const int col_to_skip) const {
  int rows = rows_ - 1, cols = cols_ - 1;
  if (rows == 0)
    rows = 1;
  if (cols == 0)
    cols = 1;
  S21Matrix minor(rows, cols);
  int minor_rows = 0;
  for (int i = 0; i < rows_; i++) {
    int minor_cols = 0;
    if (i == row_to_skip)
      continue;
    for (int j = 0; j < cols_; j++) {
      if (j == col_to_skip)
        continue;
      minor.matrix_[minor_rows][minor_cols] = (*this)(i, j);
      minor_cols++;
    }
    minor_rows++;
  }
  return minor;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double value) const noexcept {
  S21Matrix result(*this);
  result.MulNumber(value);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix operator*(double number, const S21Matrix &other) noexcept {
  S21Matrix result = other * number;
  return result;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double value) {
  MulNumber(value);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

int S21Matrix::GetRows() const noexcept { return rows_; }
int S21Matrix::GetCols() const noexcept { return cols_; }

void S21Matrix::SetRows(int new_rows) {
  if (new_rows < 0) {
    throw std::length_error("matrix rows count must be non-negative");
  }

  if (new_rows != rows_) {
    S21Matrix tmp{new_rows, cols_};

    int min = std::min(rows_, new_rows);
    for (int i = 0; i < min; ++i) {
      for (int j = 0; j < cols_; ++j) {
        tmp(i, j) = (*this)(i, j);
      }
    }

    *this = std::move(tmp);
  }
}

void S21Matrix::SetCols(int new_cols) {
  if (new_cols < 0) {
    throw std::length_error("matrix cols count must be non-negative");
  }

  if (new_cols != cols_) {
    S21Matrix tmp{rows_, new_cols};

    int min = std::min(cols_, new_cols);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < min; ++j) {
        tmp(i, j) = (*this)(i, j);
      }
    }

    *this = std::move(tmp);
  }
}