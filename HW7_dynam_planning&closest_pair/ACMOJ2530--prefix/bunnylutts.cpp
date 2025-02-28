#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000007;
const ll INF = -1e18;
int main() {
    ll n, m, a[5005], sum = 0, f[50005], g[50005];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    f[0] = 0;   g[0] = 1;
    for (int i = 1; i <= m; ++i) {
        f[i] = INF;
        g[i] = 0;
    }
    if (sum < m) {
        cout << 0 << endl;
        return 0;
    }
    if (sum == m) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int v = m; v >= 1; --v) {
            for (int k = 1; k <= v && k <= a[i]; ++k) {
                ll candi = f[v - k] + k;
                if (f[v] == candi) {
                    g[v] = (g[v] + g[v - k]) % mod;
                } else if (f[v] < candi) {
                    f[v] = candi;
                    g[v] = g[v - k];
                }
            }
        }
    }
    cout << g[m] % mod << endl;
    return 0;
}