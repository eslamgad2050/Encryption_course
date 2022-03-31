#include "matrix.h"


Matrix::Matrix(int rows_, int cols_)
{}

Matrix::Matrix(int rows_, int cols_, float val)
{}

Matrix::Matrix(int rows_, int cols_, MatrixType m_type)
{}

/*Copy constructor: to prevent shallow copy*/
Matrix::Matrix(const Matrix& m)
{}

Matrix::~Matrix()
{}

int Matrix::get_rows() const
{}

int Matrix::get_cols() const
{}

void Matrix::print() const
{}

float& Matrix::access(int r_ind, int c_ind)
{}

Matrix Matrix::operator+(const Matrix& m) const
{}

Matrix Matrix::operator-(const Matrix& m) const
{}

Matrix Matrix::operator*(float val) const
{}

Matrix Matrix::operator/(float val) const
{}

Matrix Matrix::operator*(const Matrix& m) const
{}

Matrix Matrix::operator/(const Matrix& m) const
{}

bool Matrix::operator==(const Matrix& m) const
{}

bool Matrix::operator!=(const Matrix& m) const
{}

bool Matrix::isIdentity() const
{}

bool Matrix::isIdempotent() const
{}

bool Matrix::isSquare() const
{}

bool Matrix::isSymmetric() const
{}

bool Matrix::isUpperTriangle() const
{}

bool Matrix::isLowerTriangle() const
{}

Matrix Matrix::transpose() const
{}

void Matrix::fill(float val)
{}

float Matrix::minElement() const
{}

float Matrix::maxElement() const
{}

float Matrix::determinant() const
{}

string Matrix::toString() const
{}