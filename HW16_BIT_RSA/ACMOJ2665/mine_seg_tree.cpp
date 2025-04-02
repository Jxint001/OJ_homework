#include <cstdio>
const long long MOD = 1e9+7, maxn = 1e5+5;
long long add[maxn << 2], sum[maxn << 2], a[maxn];

inline void up(long long i) {
    sum[i] = (sum[i << 1] + sum[i << 1 | 1]) % MOD;
}
void build(long long l, long long r, long long i) {
    if (l == r)  {sum[i] = a[l];  return;}
    long long mid = l + ((r - l) >> 1);
    build(l, mid, i << 1);
    build(mid + 1, r, i << 1 | 1);
    up(i);
}
inline void lazy(long long value, long long i, long long len) {
    sum[i] = (sum[i] + value * len) % MOD;
    add[i] = (add[i] + value) % MOD;
}
inline void down (long long i, long long l_len, long long r_len) {
    if (add[i] != 0) {
        lazy(add[i], i << 1, l_len);
        lazy(add[i], i << 1 | 1, r_len);
        add[i] = 0;
    }
}
void opAdd(long long x, long long w, long long value, long long l, long long r, long long i) {
    if (x <= l && r <= w) {lazy(value, i, r - l + 1);  return; }
    long long mid = l + ((r - l) >> 1);
    down(i, mid - l + 1, r - mid);
    if (x <= mid) {opAdd(x, w, value, l, mid, i << 1); }
    if (mid < w) {opAdd(x, w, value, mid + 1, r, i << 1 | 1); }
    up(i);
}
long long query(long long x, long long w, long long l, long long r, long long i) {
    if (x <= l && r <= w) {return sum[i]; }
    long long ret = 0;
    long long mid = l + ((r - l) >> 1);
    down(i, mid - l + 1, r - mid);
    if (x <= mid) {ret = (ret + query(x, w, l, mid, i << 1)) % MOD; }
    if (mid < w) {ret = (ret + query(x, w, mid + 1, r, i << 1 | 1)) % MOD; }
    return ret;
}
int main() {
    long long N, Q;  scanf("%lld%lld", &N, &Q);
    for (long long i = 1; i <= N; ++i) {scanf("%lld", &a[i]); }
    build(1, N, 1);
    while (Q-- > 0) {
        long long flag, x, w, value;  scanf("%lld", &flag);
        if (flag == 1) {
            scanf("%lld%lld", &x, &w);
            printf("%lld\n", query(x, x + w - 1, 1, N, 1));
        }
        if (flag == 2) {
            scanf("%lld%lld%lld", &x, &w, &value);
            opAdd(x, x + w - 1, value, 1, N, 1);
        }
    }
    return 0;
}