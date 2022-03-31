#include "matrix.h"
#include <random>
#include "time.h"

Matrix::Matrix(int rows_, int cols_) {
    rows = rows_;
    cols = cols_;
    data = new float *[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new float[cols];
        for (int j = 0; j < cols; ++j) {
            srandom(time(0));
            data[i][j] = random();
        }
    }
}

Matrix::Matrix(int rows_, int cols_, float val) {
    rows = rows_;
    cols = cols_;
    data = new float *[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new float[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = val;
        }
    }
}

Matrix::Matrix(int rows_, int cols_, MatrixType m_type) {
    rows = rows_;
    cols = cols_;
    data = new float *[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new float[cols];
        for (int j = 0; j < cols; ++j) {
            if (m_type == random())
                data[i][j] = random();
            else if (m_type == Identity) {
                if (i == j) {
                    data[i][j] = 1;
                } else {
                    data[i][j] = 0;
                }
            }
        }
    }
}

/*Copy constructor: to prevent shallow copy*/
Matrix::Matrix(const Matrix &m) {
    rows = m.rows;
    cols = m.cols;
    data = new float *[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new float[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete data[i];
    }
}

int Matrix::get_rows() const {
    return rows;
}

int Matrix::get_cols() const { return cols; }

void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << data[i][j] << ' ';
        }
        cout << "\n";
    }
}

float &Matrix::access(int r_ind, int c_ind) {}

Matrix Matrix::operator+(const Matrix &m) const {}

Matrix Matrix::operator-(const Matrix &m) const {}

Matrix Matrix::operator*(float val) const {}

Matrix Matrix::operator/(float val) const {}

Matrix Matrix::operator*(const Matrix &m) const {}

Matrix Matrix::operator/(const Matrix &m) const {}

bool Matrix::operator==(const Matrix &m) const {}

bool Matrix::operator!=(const Matrix &m) const {}

bool Matrix::isIdentity() const {}

bool Matrix::isIdempotent() const {}

bool Matrix::isSquare() const {}

bool Matrix::isSymmetric() const {}

bool Matrix::isUpperTriangle() const {}

bool Matrix::isLowerTriangle() const {}

Matrix Matrix::transpose() const {}

void Matrix::fill(float val) {}

float Matrix::minElement() const {}

float Matrix::maxElement() const {}

float Matrix::determinant() const {}

string Matrix::toString() const {}