#include <iostream>
typedef unsigned long long ull;

ull ROTL32(ull& x, ull n) {
    return ((x) << n | (x) >> (32-n));
}

ull inverse_ROTL32(ull& x, ull n) {
    ull ans = 0;
    ans += (x / (1 << n));
    ans += ((x % ( 1 << n)) << (32 - n));
    return ans;
}

void MIX(ull& h,ull& d) {
    d = ROTL32(d, 15); 
    h ^= d;
    h = ROTL32(h, 13);
    h = h + 0xe6546b64;
}

ull mod(ull a) {
    ull t = 0, tt = 1;
    ull rest = 0x100000000, nrest = a;
    while (nrest != 0) {
        ull q = rest / nrest;
        ull tpt = t;
        t = tt;
        tt = tpt - q * tt;
        ull tpr = rest;
        rest = nrest;
        nrest = tpr - q * nrest;
    }
    if (t < 0)  t += 0x100000000;
    return t;
}

int main() {
    ull h, n,a[60];
    std::cin >> h >> n;
    for (int i = 0; i <= n - 2; ++i)  a[i] = 0;
    //find before finnalmix
    h ^= h >> 16;
    h *= mod(h);
    h ^= h >> 13;
    h ^= h >> 16;

    h -= 0xe6546b64;
    h = inverse_ROTL32(h, 13);
    ull last = 0;
    for (int i = 0; i <= n - 2; ++i) {
        MIX(last, a[i]);
    }

    ull an = last ^ h;
    a[n - 1] = inverse_ROTL32(an, 15);
    for (int i = 0; i < n; ++i)  std::cout << a[i] << " ";
    std::cout << '\n';
    // ull p = 8;
    // p = ROTL32(p, 15);
    // p = ROTL32(p, 17);
    // std::cout << p ;
    return 0;
}