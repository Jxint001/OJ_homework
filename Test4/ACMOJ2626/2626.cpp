#include <iostream>
#include <unordered_map>
const int MOD = 1e9 + 7;
const int N = 2e5+5;
typedef long long ll;
using namespace std;
int n, a[N], f[N];
unordered_map<ll, ll> cnt;
unordered_map<ll, ll> sum;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        ll count = (cnt[a[i]-1] + cnt[a[i]+1] + 1) % MOD;
        ll add = (sum[a[i]-1] + sum[a[i]+1] + count*a[i]) % MOD;
        sum[a[i]] = (sum[a[i]] + add) % MOD;
        f[i] = (f[i-1] + add) % MOD;
        cnt[a[i]] = (cnt[a[i]] + count) % MOD;
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << "f[" << i << "]: " << f[i] << endl;
    // }
    cout << f[n] << endl;
}
// f[i] 是1到i个数的字串和