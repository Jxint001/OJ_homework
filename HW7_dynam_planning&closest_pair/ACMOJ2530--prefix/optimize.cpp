#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000007;
int main() {
    ll n, m, a[5005], f[50005];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        vector<ll> delta(m + 5, 0);
        for (int j = 0; j <= m; ++j) {
            if (f[j] > 0) {
                if (j + 1 <= m)  delta[j + 1] = (delta[j + 1] + f[j]) % mod;
                if (j + a[i] + 1 <= m)  delta[j + a[i] + 1] = (delta[j + a[i] + 1] - f[j] + mod) % mod;
            }
        }
        ll sum = 0;
        for (int j = 1; j <= m; ++j) {
            sum = (sum + delta[j]) % mod;
            f[j] = (f[j] + sum) % mod;
        }
    }
    cout << f[m] << endl;
    return 0;
}