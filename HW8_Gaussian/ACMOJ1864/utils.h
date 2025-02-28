#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream>
#include <cmath>
#include "matrix.h"

namespace sjtu {

const unsigned _alpha = 339373u;
const unsigned _beta = 514233u;
const unsigned _mod = 998244353u;
unsigned seed = 0u;
void _srand(unsigned _seed = 0u) { seed = _seed; }
unsigned _rand() {
    seed = (1ull * seed * _alpha + _beta) % _mod;
    return seed;
}
unsigned _pow(unsigned _a, unsigned _n) {
    unsigned _t = 1u;
    while (_n > 0) {
        if (_n & 1) _t = (1ull * _t * _a) % _mod;
        _a = 1ull * _a * _a % _mod;
        _n >>= 1;
    }
    return _t;
}
unsigned _inv(unsigned _a) {
    return _pow(_a, _mod - 2);
}

template <typename T>
bool equals(const Matrix<T> &lhs, const Matrix<T> &rhs) {
    if (lhs.height() != rhs.height()) return false;
    if (lhs.width() != rhs.width()) return false;
    for (int i = 0; i < lhs.height(); ++i) {
        for (int j = 0; j < lhs.width(); ++j) {
            if (!(lhs(i, j) == rhs(i, j))) return false;
        }
    }
    return true;
}

template <typename T>
Matrix<T> negative(const Matrix<T> &m) {
    Matrix<T> ret(m);
    for (int i = 0; i < m.height(); ++i) {
        for (int j = 0; j < m.width(); ++j) {
            ret(i, j) = -m(i, j);
        }
    }
    return ret;
}

template <typename T>
std::ostream& operator << (std::ostream &os, const Matrix<T> &m) {
    os << "[ ";
    for (int i = 1; i <= m.height(); ++i) {
        for (int j = 1; j <= m.width(); ++j) {
            os << m(i, j);
            if (j != m.width()) os << " ";
        }
        if (i != m.height()) os << " ; ";
    }
    os << " ]" << std::endl;;
    return os;
}

}

#endif