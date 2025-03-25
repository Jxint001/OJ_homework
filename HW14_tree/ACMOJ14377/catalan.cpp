// f(n) = \sigma_{i = 1}^n f(i-1)f(n-i)
#include <cstdio>
typedef long long ll;
const ll MOD = 1e9+7;
ll f[1005];
int main() {
    ll n;  scanf("%lld", &n);
    f[0] = f[1] = 1;
    for (ll i = 2; i <= n; ++i) {
        for (ll j = 1; j <= i; ++j) {
            f[i] = (f[i] + f[j-1] * f[i-j]) % MOD;
        }
    }
    printf("%lld\n", f[n]);
    return 0;
}