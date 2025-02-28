#include "utils.h"
#include "ring.h"
#include "group.h"

namespace sjtu {

void test3() {
    int seq1[60];
    for (int i = 0; i < 60; ++i) seq1[i] = static_cast<int>(_rand());
    
    Matrix<int> c1(1, 60, seq1);
    Matrix<int> d1(1, 60);
    Matrix<int> c2(2, 30, seq1);
    const Matrix<int> d2(2, 30);
    const Matrix<int> c3(20, 3, seq1);
    const Matrix<int> d3(20, 3);
    std::cout << c1 << d1 << c2 << d2 << c3 << d3;
    std::cout << Matrix<int>(1, 60, seq1);
    std::cout << Matrix<int>(1, 60);
    std::cout << Matrix<int>(2, 30, seq1);
    std::cout << Matrix<int>(2, 30);
    std::cout << Matrix<int>(20, 3, seq1);
    std::cout << Matrix<int>(20, 3);

    try {
        c1(1, 20) = static_cast<int>(_rand());
        d1(1, 30) = 1;
        c2(2, 14) = 0;
        std::cout << c1 << d1 << c2;
        Matrix<int>(1, 60, seq1)(1, 20) = static_cast<int>(_rand());
        Matrix<int>(1, 60)(1, 34) = 1;
        Matrix<int>(2, 30)(2, 14) = 0;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }

    try {
        c1(0, 20) = 1;
        std::cout << c1;
    }
    catch(sjtu::MatrixIndexingError& e) {
        std::cout << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }
    
    try {
        c1(-1, 10) = 1;
        std::cout << c1;
    }
    catch(sjtu::MatrixIndexingError& e) {
        std::cout << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }

    try {
        c1(1, 1000) = 1;
        std::cout << c1;
    }
    catch(sjtu::MatrixIndexingError& e) {
        std::cout << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }

    Matrix<Float> e1(1, 1);
    Matrix<Float> e2(1, 1000000);
    Matrix<Float> e3(1000000, 1);
    Matrix<Float> e4(1000, 1000);
    std::cout << Matrix<Float>(10, 10);
    std::cout << Matrix<Float>(1, 1);
    try {
        std::cout << e1(1, 1) << std::endl; 
        std::cout << e2(1, 1000) << std::endl;
        std::cout << e4(1000, 1000) << std::endl;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }
    
    Boolean *arr = new Boolean [100000];
    for (int i = 0; i < 100000; ++i) arr[i] = Boolean::rand();

    Matrix<Boolean> f1(1, 100000, arr);
    Matrix<Boolean> f2(100000, 1, arr);
    const Matrix<Boolean> f3(100, 1000, arr);
    try {
        std::cout << f1(1, 1000) << std::endl;
        std::cout << f2(10000, 1) << std::endl;
        std::cout << f3(100, 1000) << std::endl;
        std::cout << Matrix<Boolean>(1, 100000, arr)(1, 1000) << std::endl;
        std::cout << Matrix<Boolean>(100000, 1, arr)(10000, 1) << std::endl;
        std::cout << Matrix<Boolean>(100, 1000, arr)(100, 1000) << std::endl;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }

    Matrix<int> g1(c1);
    Matrix<int> g2(d2);
    const Matrix<Boolean> g3(f3);
    const Matrix<Float> g4(e4);
    Matrix<Float> g5(Matrix<Float>(10, 10));
    const Matrix<SemiRing> g6(Matrix<SemiRing>(1, 10));
    std::cout << g1 << g2 << g5 << g6;
    try {
        std::cout << g3(100, 1000) << std::endl;
        std::cout << g4(1000, 1000) << std::endl;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }

    delete [] arr;

    try {
        std::cout << c1(1, 2) << std::endl;
    }
    catch(sjtu::MatrixIndexingError& e) {
        std::cout << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }

    try {
        std::cout << d2(1, 2) << std::endl;
    }
    catch(sjtu::MatrixIndexingError& e) {
        std::cout << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }

    try {
        std::cout << c3(1, 2) << std::endl;
    }
    catch(sjtu::MatrixIndexingError& e) {
        std::cout << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }

    try {
        std::cout << e2(1, 2) << std::endl;
    }
    catch(sjtu::MatrixIndexingError& e) {
        std::cout << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }

    try {
        std::cout << c1(-1, 3) << std::endl;
    }
    catch(sjtu::MatrixIndexingError& e) {
        std::cout << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }

    try {
        std::cout << c1(0, 2) << std::endl;
    }
    catch(sjtu::MatrixIndexingError& e) {
        std::cout << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }
    
    try {
        std::cout << c1(1000, 2000) << std::endl;
    }
    catch(sjtu::MatrixIndexingError& e) {
        std::cout << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "unexpected error" << std::endl;
    }

    c1 = c1;
    d1 = d1;
    std::cout << c1 << d1;
    c1 = d1;
    d1 = c1;
    std::cout << c1 << d1;

    c1 = c2;
    c2 = d3;
    std::cout << c1 << c2;
}

}

int main() {
    freopen("my.ans", "w", stdout);
    sjtu::_srand(3u);
    sjtu::test3();
}
