#include <cstdio>
#include <deque>
#include <climits>
#include <cmath>
typedef long long ll;
ll n, m, s, a[5005], prev[5005], cur[5005];
int main() {
    scanf("%lld%lld%lld", &n, &m, &s);
    for (ll i = 0; i <= m; ++i) {
        prev[i] = LONG_LONG_MIN;
    }
    prev[0] = 0;
    for (ll i = 1; i <= n; ++i) {  //年份
        scanf("%lld", &a[i]);
        std::deque<ll> dq;
        ll prev_end = (i == ll(1))? ll(-1): ll(0);

        for (ll j = 1; j <= m; ++j) {  //人数
            ll L = std::max(i == ll(1)? ll(0): ll(1), j - 1);
            ll R = std::min(m, ll(j + s - 1));
            
            for (ll x = prev_end + 1; x <= R; ++x) {
                if (prev[x] == LONG_LONG_MIN) {continue; }
                while (!dq.empty() && prev[x] >= prev[dq.back()]) {dq.pop_back(); }
                dq.push_back(x);
            }
            prev_end = R;
            
            while (!dq.empty() && dq.front() < L) {dq.pop_front(); }
           
            if (!dq.empty()) {cur[j] = prev[dq.front()] + a[i] * j; }
            else {cur[j] = LONG_LONG_MIN; }
        }
        for (ll j = 0; j <= m; ++j) prev[j] = cur[j];
    }
    ll ans = LONG_LONG_MIN;
    for (ll j = 1; j <= m; ++j) {
        ans = cur[j] > ans? cur[j]: ans;
    }
    printf("%lld\n", ans);
    return 0;
}