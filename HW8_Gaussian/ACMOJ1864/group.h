#ifndef __GROUP_LIKE_H__
#define __GROUP_LIKE_H__

#include <cmath>
#include "utils.h"

namespace sjtu {

struct Float {
    static Float zero() {
        return Float(0u);
    }
    static Float ident() {
        return Float(1u);
    }
    static Float rand() {
        return Float(_rand() % _mod);
    }
    unsigned frac;
    Float(): frac(0u) {}
    Float(unsigned _frac): frac(_frac % _mod) {}
    Float(const Float &o): frac(o.frac) {}
    Float& operator = (const Float &o) {
        if (this == &o) return *this;
        frac = o.frac;
        return *this;
    }
    bool operator == (const Float &o) const {
        return frac == o.frac;
    }
    Float operator + () const {
        return Float(frac);
    }
    Float operator - () const {
        return Float(_mod - frac);
    }
    Float operator + (const Float &o) const {
        return Float((frac + o.frac) % _mod);
    }
    Float operator - (const Float &o) const {
        return Float((0ull + _mod + frac - o.frac) % _mod);
    }
    Float operator * (const Float &o) const {
        return Float(1ull * frac * o.frac % _mod);
    }
    Float operator / (const Float &o) const {
        return Float(1ull * frac * _inv(o.frac) % _mod);
    }
    friend std::ostream& operator << (std::ostream& os, const Float &o) {
        os << "<" << o.frac << ">";
        return os;
    }
    ~Float() = default;
};

struct Complex {
    static Complex zero() {
        return Complex(Float(0), Float(0));
    }  
    static Complex ident() {
        return Complex(Float(1), Float(0));
    }
    static Complex rand() {
        return Complex(Float::rand(), Float::rand());
    }
    Float real, imag;
    Complex(): real(), imag() {}
    Complex(Float _real, Float _imag): real(_real), imag(_imag) {}
    Complex(const Complex &o): real(o.real), imag(o.imag) {}
    Complex& operator = (const Complex &o) {
        if (this == &o) return *this;
        real = o.real, imag = o.imag;
        return *this;
    }
    bool operator == (const Complex &o) const {
        return real == o.real && imag == o.imag;
    }
    Complex operator + () const {
        return Complex(+real, +imag);
    }
    Complex operator - () const {
        return Complex(-real, -imag);
    }
    Complex operator + (const Complex &o) const {
        return Complex(real + o.real, imag + o.imag);
    }
    Complex operator - (const Complex &o) const {
        return Complex(real - o.real, imag - o.imag);
    }
    Complex operator * (const Complex &o) const {
        return Complex(real * o.real - imag * o.imag, real * o.imag + imag * o.real);
    }
    Complex operator / (const Complex &o) const {
        Float mod = o.real * o.real + o.imag * o.imag;
        return Complex((real * o.real + imag * o.imag) / mod, (imag * o.real - real * o.imag) / mod);
    }
    friend std::ostream& operator << (std::ostream &os, const Complex &c) {
        os << "(" << c.real << " + " << c.imag << "i)";
        return os;
    }
    ~Complex() = default;
};

}

#endif