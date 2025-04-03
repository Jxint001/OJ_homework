#include <cstdio>
int y, n, e, flag;
long long fastpow(int x, int e, int mod) {
    long long ret = 1, tmp = x;
    while (e > 0) {
        if (e & 1) {
            ret = (ret * tmp) % mod;
        }
        tmp = (tmp * tmp) % mod;
        e >>= 1;
    }
    return ret;
}
struct derive{
    int a, b, d; // gcd(e, (p-1)(q-1)) = ae + b(p-1)(q-1) = 1 = d
    derive(int A, int B, int D) : a(A), b(B), d(D) {}
};
derive extendedEUC(int x, int y) {
    if (y == 0)  return derive(1, 0, x);
    derive cur = extendedEUC(y, x % y);
    return derive(cur.b, cur.a - (x / y) * cur.b, cur.d);
}
int main() {
    scanf("%d%d%d%d", &y, &n, &e, &flag);
    int p = 1, q = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            p = i, q = n / i;
            break;
        }
    }
    int phi = (p - 1) * (q - 1);
    derive ans = extendedEUC(e, phi);
    int d = (ans.a % phi + phi) % phi;
    int x = fastpow(y, d, n);
    if (!flag) {
        printf("%d\n", x);
    } else {
        printf("%d %d\n", x, d);
    }
    return 0;
}
