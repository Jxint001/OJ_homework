#include <cstdio>
typedef long long ll;
constexpr ll MAXN = 100005;
ll n, q, m, a[MAXN], sum[MAXN << 2], add[MAXN << 2], mtp[MAXN << 2];
inline void up(ll i) {
    sum[i] = (sum[i << 1] + sum[(i << 1) | 1]) % m;
}
void build(ll l, ll r, ll i) {
    if (l == r) {sum[i] = a[l] % m;  return; }
    ll mid = (l + r) >> 1;
    build(l, mid, i << 1);
    build(mid+1, r, (i << 1) | 1);
    up(i);
}
void lazy(ll i, ll num, ll k1, ll k2) {
    sum[i] = (sum[i] * k2 + k1 * num) % m;
    add[i] = (add[i] * k2 + k1) % m;
    mtp[i] = (mtp[i] * k2) % m;
}
void down(ll i, ll ln, ll rn) {
    if (add[i] != 0 || mtp[i] != 1) {
        lazy(i << 1, ln, add[i], mtp[i]);
        lazy((i << 1) | 1, rn, add[i], mtp[i]);
        add[i] = 0;
        mtp[i] = 1;
    }
}
void plus(ll x, ll y, ll k, ll l, ll r, ll i) {
    if (x <= l && r <= y) {lazy(i, r -l + 1, k, 1);  return; }
    ll mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);
    if (x <= mid) {
        plus(x, y, k, l, mid, i << 1);
    }
    if (y > mid) {
        plus(x, y, k, mid + 1, r, (i << 1) | 1);
    }
    up(i);
}
void mult(ll x, ll y, ll k, ll l, ll r, ll i) {
    if (x <= l && r <= y) {lazy(i, r -l + 1, 0, k);  return; }
    ll mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);
    if (x <= mid) {
        mult(x, y, k, l, mid, i << 1);
    }
    if (y > mid) {
        mult(x, y, k, mid + 1, r, (i << 1) | 1);
    }
    up(i);
}
ll query(ll x, ll y, ll l, ll r, ll i) {
    if (x <= l && r <= y) {return sum[i] % m; }
    ll mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);
    if (y <= mid) {
        return query(x, y, l, mid, i << 1) % m;
    }
    if (x > mid) {
        return query(x, y, mid + 1, r, (i << 1) | 1) % m;
    }
    return ((query(x, y, l, mid, i << 1) % m) + (query(x, y, mid + 1, r, (i << 1) | 1) % m)) % m;
}
int main() {
    scanf("%lld%lld%lld", &n, &q, &m);
    for (ll i = 1; i <= n; ++i) {scanf("%lld", &a[i]); }
    for (ll i = 0; i <= 4 * n; ++i) {mtp[i] = 1; add[i] = 0; }
    build(1, n, 1);
    while(q-- > 0) {
        ll flag;
        scanf("%lld", &flag);
        if (flag == 1) {
            ll x, y, k;
            scanf("%lld%lld%lld", &x, &y, &k);
            mult(x, y, k%m, 1, n, 1);
        }
        if (flag == 2) {
            ll x, y, k;
            scanf("%lld%lld%lld", &x, &y, &k);
            plus(x, y, k%m, 1, n, 1);
        }
        if (flag == 3) {
            ll x, y;
            scanf("%lld%lld", &x, &y);
            printf("%lld\n", query(x, y, 1, n, 1));
        }
    }
    return 0;
}