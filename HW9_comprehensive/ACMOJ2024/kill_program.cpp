#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 100005;
ll n, s, ans, a[N], t[N], maxt = LONG_LONG_MAX, minti = LONG_LONG_MAX, maxti = 0;
bool compute(const ll& time) {
    ll sum = 0, maxleak = 0;
    for (ll i = 0; i < n; ++i) {
        ll tp =  (t[i] < time) ?  a[i] * (time - t[i]) : 0;
        sum += tp;
        maxleak = max(maxleak, tp);
    }
    if (sum > s && sum - s > maxleak) { return false; }
    return true;
}
int main() {
    cin >> n >> s;
    bool all0 = true;
    ll cnt = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> t[i] >> a[i];
        if (a[i] > 0) { maxt = min(maxt, a[i]); all0 = false; cnt++;}
        minti = min(minti, t[i]);
        maxti = max(maxti, t[i]);
    }
    maxt = s / maxt + maxti + 1;
    ll left = minti, ri = maxt, mid = 0;
    if (all0 || cnt == 1) {
        cout << -1 << endl;
        return 0;
    }
    bool f;
    while (left <= ri) {
        mid = left + (ri - left) / 2;
        f = compute(mid);
        if (f) {
            ans = mid;
            left = mid + 1;
        } else {
            ri = mid - 1;
        }
    }
    cout << ans + 1 << endl;
    
    return 0;
}