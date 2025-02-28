#include <iostream>
using namespace std;
int main() {
    long long n, W;
    cin >> n >> W;
    long long w[805], v[805], c[805];
    for (size_t i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i] >> c[i];
    }
    unsigned long long nw[30000], nv[30000], f[10005];
    long long cnt = 1;
    for (long long i = 1; i <= n; ++i) {
        long long k = 1;
        while (c[i] - (1 << k) + 1 > 0 && k <= 31) {
            nw[cnt] = w[i] * (1 << (k - 1));
            nv[cnt] = v[i] * (1 << (k - 1));
            ++k;  ++cnt;
        }
        --k;
        nw[cnt] = w[i] * (c[i] - (1 << k) + 1);
        nv[cnt] = v[i] * (c[i] - (1 << k) + 1);
        ++cnt;
    }
    for (long long i = 0; i <= W; ++i)  f[i] = 0;
    for (long long i = 1; i < cnt; ++i) {
        for (long long l = W; l >= nw[i]; --l) {
            f[l] = max(f[l], f[l - nw[i]] + nv[i]);
        }
    }
    cout << f[W] << endl;
    return 0;
}