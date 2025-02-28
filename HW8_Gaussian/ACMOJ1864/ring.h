#ifndef __RING_LIKE_H__
#define __RING_LIKE_H__

#include <vector>
#include "utils.h"

namespace sjtu {

struct Boolean {
    static Boolean zero() {
        return Boolean(false);
    }
    static Boolean ident() {
        return Boolean(true);
    } 
    static Boolean rand() {
        return Boolean(_rand() % 2 == 1);
    }
    bool value;
    Boolean(): value(false) {}
    Boolean(bool _value): value(_value) {}
    Boolean(const Boolean &o): value(o.value) {}
    Boolean& operator = (const Boolean &o) {
        if (this == &o) return *this;
        value = o.value; 
        return *this;
    }
    bool operator == (const Boolean &o) const {
        return value == o.value;
    }
    Boolean operator + () const {
        return Boolean(value);
    } 
    Boolean operator + (const Boolean &o) const {
        return Boolean(value || o.value);
    }
    Boolean operator * (const Boolean &o) const {
        return Boolean(value && o.value);
    }
    friend std::ostream& operator << (std::ostream& os, const Boolean &o) {
        os << (o.value? "true": "false");
        return os;
    }
    ~Boolean() = default;
};

struct Ring {
    static Ring zero() {
        return Ring(0, 0);
    }
    static Ring ident() {
        return Ring(1, 0);
    }
    static Ring rand() {
        return Ring(static_cast<int>(_rand()), static_cast<int>(_rand()));
    }
    unsigned a, b;
    Ring(): a(0), b(0) {}
    Ring(unsigned _a, unsigned _b): a(_a), b(_b) {}
    Ring(const Ring &o): a(o.a), b(o.b) {}
    Ring& operator = (const Ring &o) {
        if (this == &o) return *this;
        a = o.a, b = o.b; 
        return *this;
    }
    bool operator == (const Ring &o) const {
        return a == o.a && b == o.b;
    }
    Ring operator + () const {
        return Ring(+a, +b);
    }
    Ring operator - () const {
        return Ring(-a, -b);
    }
    Ring operator + (const Ring &o) const {
        return Ring(a + o.a, b + o.b);
    }
    Ring operator - (const Ring &o) const {
        return Ring(a - o.a, b - o.b);
    }
    Ring operator * (const Ring &o) const {
        return Ring(a * o.a + 2u * b * o.b, a * o.b + b * o.a);
    }
    friend std::ostream& operator << (std::ostream& os, const Ring &o) {
        os << "(" << o.a << " + " << o.b << "*sqrt2)";
        return os;
    }
    ~Ring() = default;
};

struct SemiRing {
    static SemiRing zero() {
        return SemiRing(-1);
    }
    static SemiRing ident() {
        return SemiRing(0u);
    }
    static SemiRing rand() {
        return SemiRing(_rand());
    }
    unsigned w;
    SemiRing(): w(0u) {}
    SemiRing(unsigned _w): w(_w) {}
    SemiRing(const SemiRing &o): w(o.w) {}
    bool operator == (const SemiRing &o) const {
        return w == o.w;
    }
    SemiRing operator + (const SemiRing &o) const {
        return SemiRing(std::min(w, o.w));
    }
    SemiRing operator * (const SemiRing &o) const {
        return SemiRing(w + o.w);
    }
    friend std::ostream& operator << (std::ostream& os, const SemiRing &o) {
        os << o.w;
        return os;
    }
    ~SemiRing() = default;
};

struct BigInt {
    static BigInt zero() {
        return BigInt(0);
    }
    static BigInt ident() {
        return BigInt(1);
    }
    static BigInt rand() {
        return BigInt(_rand());
    }

    std::vector<unsigned> num;
    BigInt() {
        num.clear();
        num.push_back(0);
    }
    BigInt(unsigned _num) {
        num.clear();
        if (_num == 0) num.push_back(0);
        else {
            while(_num > 0) {
                num.push_back(_num % 10);
                _num /= 10;
            }
        }
    }
    BigInt(const BigInt &o) {
        num.clear();
        for (unsigned x: o.num) num.push_back(x); 
    }
    BigInt& operator = (const BigInt &o) {
        if (this == &o) return *this;
        num.clear();
        for (int x: o.num) num.push_back(x);
        return *this;
    }
    bool operator == (const BigInt &o) const {
        if (num.size() != o.num.size()) return false;
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] != o.num[i]) return false;
        }
        return true;
    }
    BigInt operator + (const BigInt &o) const {
        int _siz = num.size();
        int _osiz = o.num.size();
        BigInt ret;
        ret.num.clear();
        int c = 0, i = 0;
        while (i < _siz || i < _osiz) {
            if (i < _siz) c += num[i];
            if (i < _osiz) c += o.num[i]; 
            ret.num.push_back(c % 10);
            c /= 10, i++;
        }
        while(c > 0) {
            ret.num.push_back(c % 10);
            c /= 10;
        }
        return ret;
    }
    BigInt operator * (const BigInt &o) const {
        int _size = num.size();
        int _osize = o.num.size();
        BigInt ret;
        ret.num.clear();
        long long c = 0;
        for (int i = 0; i < _size + _osize - 1; ++i) {
            for (int j = 0; j < _size; ++j) {
                int k = i - j;
                if (k >= 0 && k < _osize) {
                    c += num[j] * o.num[k];
                }
            }
            ret.num.push_back(c % 10);
            c /= 10;
        }
        while(c > 0) {
            ret.num.push_back(c % 10);
            c /= 10;
        }
        return ret;
    }
    friend std::ostream& operator << (std::ostream& os, const BigInt &o) {
        for (int i = o.num.size() - 1; i >= 0; --i) os << o.num[i];
        return os;
    } 
    ~BigInt() = default;
};

}

#endif