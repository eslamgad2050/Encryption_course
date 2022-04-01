//by Eslam Gad
#include "matrix.h"
#include <random>
#include "time.h"

using namespace std;

Matrix::Matrix(int rows_, int cols_) {
    rows = rows_;
    cols = cols_;
    data = new float *[rows];

    for (int i = 0; i < rows; ++i) {
        data[i] = new float[cols];
        for (int j = 0; j < cols; ++j) {
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
    srandom(time(0));
    for (int i = 0; i < rows; ++i) {
        data[i] = new float[cols];
        for (int j = 0; j < cols; ++j) {
            if (m_type == Random) { data[i][j] = random(); }
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

float &Matrix::access(int r_ind, int c_ind) {
    /*if (r_ind > rows || c_ind > cols) {
       static float x = 0;
        return x;
    }*/
    return *(&data[r_ind][c_ind]);
}

Matrix Matrix::operator+(const Matrix &m) const {
    Matrix *result = new Matrix(rows, cols, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result->data[i][j] = data[i][j] + m.data[i][j];
        }
    }
    return *result;
}

Matrix Matrix::operator-(const Matrix &m) const {
    Matrix *result = new Matrix(rows, cols, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result->data[i][j] = data[i][j] - m.data[i][j];
        }
    }
    return *result;
}

Matrix Matrix::operator*(float val) const {
    Matrix result(rows, cols, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * val;
        }
    }
    return result;
}

Matrix Matrix::operator/(float val) const {
    Matrix *result = new Matrix(rows, cols, 0);
    if (val == 0) {
        return *result;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result->data[i][j] = data[i][j] / val;
        }
    }
    return *result;
}

Matrix Matrix::operator*(const Matrix &m) const {
    Matrix *result = new Matrix(rows, m.cols, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result->data[i][j] += data[i][k] * m.data[k][j];
            }
        }
    }
    return *result;
}

Matrix Matrix::operator/(const Matrix &m) const {
    float det = m.determinant();
    Matrix *cofactors = new Matrix(rows, cols, 0);
    if (det == 0 || !m.isSquare() || !this->isSquare()) { return *cofactors; }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Matrix minor(rows - 1, cols - 1, 0);
            for (int k = 0; k < rows - 1; ++k) {
                for (int l = 0; l < cols - 1; ++l) {
                    int r = k < i ? k : k + 1,
                            c = l < j ? l : l + 1;
                    minor.data[k][l] = data[r][c];
                }
            }
            cofactors->data[i][j] = minor.determinant() * ((i + j) % 2 == 0 ? 1 : -1);
        }
    }
    Matrix adjoint = cofactors->transpose(), result = (adjoint / det);
    result.print();
    return *this * result;
}

bool Matrix::operator==(const Matrix &m) const {
    if (rows != m.rows || cols != m.cols) { return false; }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] != m.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &m) const {
    return !(*this == m);
}

bool Matrix::isIdentity() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if ((i == j && data[i][j] != 1) || (i != j && data[i][j] != 0))return false;
        }
    }
    return true;
}

bool Matrix::isIdempotent() const {
    if (rows != cols) {
        return false;
    }
    return (*this * *this) == *this;
}

bool Matrix::isSquare() const {
    if (cols == rows) { return true; }
    else { return false; }
}

bool Matrix::isSymmetric() const {
    return *this == this->transpose();
}

bool Matrix::isUpperTriangle() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i > j && data[i][j] != 0) { return false; }
        }
    }
    return true && isSquare();
}


bool Matrix::isLowerTriangle() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i < j && data[i][j] != 0) { return false; }
        }
    }
    return true && isSquare();
}

Matrix Matrix::transpose() const {
    Matrix *result = new Matrix(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result->data[j][i] = data[i][j];
        }
    }
    return *result;
}

void Matrix::fill(float val) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = val;
        }
    }
}

float Matrix::minElement() const {
    float max = MAXFLOAT;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] <
                max) {
                max = data[i][j];
            }
        }
    }
    return max;
}

float Matrix::maxElement() const {
    float max = MAXFLOAT * -1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] > max) {
                max = data[i][j];
            }
        }
    }
    return max;
}

float Matrix::determinant() const {
    float result = 0;
    if (rows != cols) {
        return 0;
    }
    if (cols == 1) { return data[0][0]; }
    else if (cols == 2) {
        result += data[0][0] * data[1][1];
        result -= data[0][1] * data[1][0];
    } else {
        for (int i = 0; i < rows; ++i) {
            Matrix sub(rows - 1, cols - 1, 0);
            for (int j = 0; j < rows - 1; ++j) {
                for (int k = 0; k < cols - 1; ++k) {
                    int temp = 0;
                    if (k >= i) {
                        temp = k + 1;
                    } else {
                        temp = k;
                    }
                    sub.data[j][k] = data[j + 1][temp];
                }
            }
            result += data[0][i] * sub.determinant() * (i % 2 == 0 ? 1 : -1);
        }
    }
}

string Matrix::toString() const {
    string result = "";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ostringstream os;
            os << data[i][j];
            result += os.str() + " ";
        }
        result += "\n";
    }
    return result;
}