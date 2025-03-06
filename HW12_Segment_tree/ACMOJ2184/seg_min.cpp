#include <cstdio>
#include <climits>
typedef long long ll;
constexpr ll MAXN = 5e5+5;
ll h[MAXN], n, m, boom[MAXN << 2], sup[MAXN << 2];  // boom记录当前区间被扔过的炸弹的最小值（如果被扔过的话）, sup记录当前区间扔过炸弹的最大值
bool changed[MAXN << 2];  // 记录当前区间是否被新扔过炸弹
inline ll read() {
    ll c = getchar(), x = 0;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x;
}
void up(ll i) {
    sup[i] = sup[i << 1] > sup[i << 1 | 1] ? sup[i << 1] : sup[i << 1 | 1];
}
inline void lazy(ll x, ll i) {
    boom[i] = changed[i] ? (x < boom[i] ? x : boom[i]) : x;
    sup[i] = x > sup[i] ? x : sup[i];
    changed[i] = 1;
    //prllf("inlazy: boom %d : %d  changed %d : %d\n", i, boom[i], i, changed[i]);
}
inline void down(ll i){
    if (changed[i]) {
        lazy(boom[i], i << 1);
        lazy(boom[i], i << 1 | 1);
        changed[i] = 0;
    }
}
void update(ll x, ll l, ll r, ll curl, ll curr, ll i) {
    if (changed[i] && sup[i] <= x) {return; }
    if (changed[i] && boom[i] <= x) {return; }
    if (l <= curl && curr <= r) {lazy(x, i);  return; }
    down(i);
    ll mid = (curl + curr) >> 1;
    if (l <= mid) {
        update(x, l, r, curl, mid, i << 1);
    }
    if (r > mid) {
        update(x, l, r, mid + 1, curr, i << 1 | 1);
    }
    up(i);
}
void query(ll* h, ll curl, ll curr, ll i) {
    if (curl == curr) {
        if (changed[i]) h[curl] = h[curl] > boom[i] ? boom[i] : h[curl];
        return;
    }
    down(i);
    ll mid = (curl + curr) >> 1;
    query(h, curl, mid, i << 1);
    query(h, mid + 1, curr, i << 1 | 1);
}
int main() {
    n = read(); m = read();
    for (ll i = 1; i <= n; ++i) {h[i] = read(); }
    ll x, l, r;
    for (ll i = 1; i <= n * 4; ++i) {sup[i] = INT_MIN; }
    while (m-- > 0) {
        x = read(); l = read(); r = read();
        update(x, l, r, 1, n, 1);
    }
    query(h, 1, n, 1);
    for (ll i = 1; i <= n; ++i) {printf("%lld ",h[i]); }
    printf("\n");
    //for (ll i = 1; i <= 9; ++i)  printf("boom %d : %d  changed %d : %d\n", i, boom[i], i, changed[i]);
    return 0;
}