#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
const long long INF = 1e18;
ll n;
// FIXME: reimplement with long long int
ll pow_2(ll x) {
    return x * x;
}

struct point {
    ll x, y;
    point (ll _x, ll _y) : x(_x), y(_y) {}
    point ():x(0), y(0) {}
    ll distance_2 (const point & other) const {
        // TODO: implement distance_2
        return pow_2(other.x- x) + pow_2(other.y - y);
    }
};

vector<point> a;
point bl[200005];
point br[200005];
point tmp[200005];
ll solve (ll l, ll r) {
    // TODO: implement solve
    if (r - l <= 2) {
        if (r - l <= 1) {
            return INF;
        }
        return a[l].distance_2(a[l + 1]);
    }
    ll mid = l + (r - l) / 2;
    ll lm = solve(l, mid);   ll rm = solve(mid, r);

    ll del = min(lm, rm);

    ll blsize = 0;
    for (ll i = l; i < mid; ++i) {
        if (pow_2(a[mid].x - a[i].x) < del) {
            bl[blsize++] = a[i];
        }
    }
    ll brsize = 0;
    for (ll i = mid; i < r; ++i) {
        if (pow_2(a[i].x - a[mid].x) < del) {
            br[brsize++] = a[i];
        }
    }

    sort(br, br + brsize, [](auto &u, auto &v) {
        return u.y < v.y;
    });
    
    auto index = [del, brsize](ll t) {
        ll a1 = 0, b = brsize - 1;
        ll ans = LONG_LONG_MIN;
        while (a1 <= b) {
            ll m = a1 + (b - a1) / 2;
            ll dis = br[m].y - bl[t].y;
            if (dis * dis <= 4 * del) {
                if (ans < m)  ans = m;
                a1 = m + 1;
            }
            if (dis * dis > 4 * del) {
                if (dis >= 0)  b = m - 1;
                if (dis < 0)  a1 = m + 1;
            }
        }
        return ans;
    };
    ll mid_min = INF;
    for (ll i = 0; i < blsize; ++i) {
        ll rindex = index(i);
        if (rindex == LONG_LONG_MIN)  continue;
        while (rindex >= 0 && pow_2(br[rindex].y - bl[i].y) <= 4 * del) {
            ll t = bl[i].distance_2(br[rindex]);
            if (t < mid_min)  mid_min = t;
            --rindex;
        }
    }
    return min(del, mid_min);
}

int main() {
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        a.push_back(point(x, y));
    }
    sort(a.begin(), a.end(), [](auto &u, auto &v) {
        return u.x < v.x || (u.x == v.x && u.y < v.y);
    });
    cout << solve(0, n) << endl;
}