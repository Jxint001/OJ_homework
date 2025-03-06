#include <cstdio>
typedef long long ll;
constexpr ll MAXN = 100005;
ll n, m, a[MAXN], sum[MAXN << 2], add[MAXN << 2];
void up(int i) {
    sum[i] = sum[i << 1] + sum[(i << 1) | 1];
}
void build(int l, int r, int i) {
    if (l == r) {sum[i] = a[l];  return; }
    int mid = (l + r) >> 1;
    build(l, mid, i << 1);
    build(mid+1, r, (i << 1) | 1);
    up(i);
}
void lazy(int i, int num, int k) {
    sum[i] += k * num;
    add[i] += k;
}
void down(int i, int ln, int rn) {
    if (add[i] != 0) {
        lazy(i << 1, ln, add[i]);
        lazy((i << 1) | 1, rn, add[i]);
        add[i] = 0;
    }
}
void plus(int x, int y, int k, int l, int r, int i) {
    if (x <= l && r <= y) {lazy(i, r -l + 1, k);  return; }
    int mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);
    if (x <= mid) {
        plus(x, y, k, l, mid, i << 1);
    }
    if (y > mid) {
        plus(x, y, k, mid + 1, r, (i << 1) | 1);
    }
    up(i);
}
ll query(int x, int y, int l, int r, int i) {
    if (x <= l && r <= y) {return sum[i]; }
    int mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);
    if (y <= mid) {
        return query(x, y, l, mid, i << 1);
    }
    if (x > mid) {
        return query(x, y, mid + 1, r, (i << 1) | 1);
    }
    return query(x, y, l, mid, i << 1) + query(x, y, mid + 1, r, (i << 1) | 1);
}
int main() {
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; ++i) {scanf("%lld", &a[i]); }
    build(1, n, 1);
    while(m-- > 0) {
        int flag;
        scanf("%d", &flag);
        if (flag == 1) {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            plus(x, y, k, 1, n, 1);
        }
        if (flag == 2) {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(x, y, 1, n, 1));
        }
    }
    return 0;
}