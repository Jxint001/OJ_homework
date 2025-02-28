#ifndef MATRIX_H_
#define MATRIX_H_

#include <exception>
// just include whatever you want

namespace sjtu {

class MatrixSizeError : public std::exception {
 public:
  const char* what() noexcept {
    return "matrix size mismatch";
  }
};
class MatrixIndexingError : public std::exception {
 public:
  const char* what() noexcept {
    return "invalid matrix indexing";
  }
};

template <typename T>
class Matrix {
 private:
  int h, w;
  // TODO: choose your way to store elements in the matrix
  T** mat = nullptr;

 public:
  int height() const {
    return h;
  }
  int width() const {
    return w;
  }

  Matrix() = delete;
  Matrix(int h_, int w_, T* seq = nullptr) {
    // TODO
    h = h_;
    w = w_;
    mat = new T*[h];
    if (seq == nullptr) {
      for (int i = 0; i < h; ++i) {
        mat[i] = new T[w];
        for (int j = 0; j < w; ++j) {
          mat[i][j] = T();
        }
      }
    } else {
      for (int i = 0; i < h; ++i) {
        mat[i] = new T[w];
        for (int j = 0; j < w; ++j) {
          mat[i][j] = seq[i * w + j];
        }
      }
    }
  }
  Matrix(const Matrix& o) {
    // TODO
    h = o.h;
    w = o.w;
    mat = new T*[h];
    for (int i = 0; i < h; ++i) {
      mat[i] = new T[w];
      for (int j = 0; j < w; ++j) {
        mat[i][j] = o.mat[i][j];
      }
    }
  }

  Matrix& operator= (const Matrix& rhs) {
    // TODO
    if (this != &rhs) {
      for (int i = 0; i < h; ++i) {
          delete[] mat[i];
      }
      delete[] mat;
      h = rhs.h;
      w = rhs.w;
      mat = new T*[h];
      for (int i = 0; i < h; ++i) {
        mat[i] = new T[w];
        for (int j = 0; j < w; ++j) {
          mat[i][j] = rhs.mat[i][j];
        }
      }
    }
    return *this;
  }

  T& operator() (int row, int col) {
    // TODO
    if (row < 1 || row > h || col < 1 || col > w) {
      throw MatrixIndexingError();
    }
    return mat[row - 1][col - 1];
  }

  const T& operator() (int row, int col) const {
    // TODO
    if (row < 1 || row > h || col < 1 || col > w) {
      throw MatrixIndexingError();
    }
    return mat[row - 1][col - 1];
  }

  Matrix operator* (const Matrix& rhs) const {
    // TODO
    if (w != rhs.h) {
      throw MatrixSizeError();
    } else {
      T* seq = new T[h * rhs.w];
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < rhs.w; ++j) {
          T tp = 0;
          for (int k = 0; k < w; ++k) {
            tp = tp + mat[i][k] * rhs.mat[k][j];
          }
          seq[i * rhs.w + j] = tp;
        }
      }
      Matrix<T> temp(h, rhs.w, seq);
      delete[] seq;
      return temp;
    }
  }

  Matrix operator+ (const Matrix& rhs) const {
    // TODO
    if (h == rhs.h && w == rhs.w) {
      T* seq = new T[h * w];
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          seq[i * w + j] = mat[i][j] + rhs.mat[i][j];
        }
      }
      Matrix<T> temp(h, w, seq);
      delete[] seq;
      return temp;
    } else if (h == 1 && rhs.w == 1) {
      T* seq = new T[rhs.h * w];
      for (int i = 0; i < rhs.h; ++i) {
        for (int j = 0; j < w; ++j) {
          seq[i * w + j] = mat[0][j] + rhs.mat[i][0];
        }
      }
      Matrix<T> temp(rhs.h, w, seq);
      delete[] seq;
      return temp;
    } else if (w == 1 && rhs.h == 1) {
      T* seq = new T[h * rhs.w];
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < rhs.w; ++j) {
          seq[i * rhs.w + j] = mat[i][0] + rhs.mat[0][j];
        }
      }
      Matrix<T> temp(h, rhs.w, seq);
      delete[] seq;
      return temp;
    } else {
      throw MatrixSizeError();
    }
  }

  ~Matrix() {
    // TODO
    for (int i = 0; i < h; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
  }
};

} // namespace sjtu

#endif // MATRIX_H_