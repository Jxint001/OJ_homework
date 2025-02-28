#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ll n, w[505], dp[505][505], ans;
    cin >> n;
    for (int i = 1; i <= n + 1; ++i) {
        cin >> w[i];
        dp[i][i] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1, k = i; k <= n && j <= n; ++j, ++k) {
            ll mindp = 1e18;
            for (int p = j; p <= k - 1; ++p) {
                ll tp = dp[j][p] + dp[p + 1][k] + w[j] * w[p + 1] * w[k + 1];
                mindp = min(mindp, tp);
            }
            dp[j][k] = mindp;
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}