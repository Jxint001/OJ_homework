#include <climits>
#include <cstdio>
#include <algorithm>
const int maxn = 5e4+5, maxe = 5e5+5;
typedef long long ll;
int n, m, q, head[maxn], hmin[maxn], total = 1;
struct E{
    int u, to, next;
    ll w;
    bool operator <(const E& other) {
        return w < other.w;
    }
}e[maxe << 1], emin[maxn << 1];
inline void edge(int u, int v, ll w, bool flg) {
    if (!flg) {
        e[total] = {u, v, head[u], w};
        head[u] = total++;
    } else {
        emin[total] = {u, v, hmin[u], w};
        hmin[u] = total++;
    }
}

// start: generate MST
int rep[maxn];

int findroot(int x) {return rep[x] == x ? x : rep[x] = findroot(rep[x]); }

void Merge(int x, int y) {
    x = findroot(x);
    y = findroot(y);
    rep[x] = y;
}

void Kruskal() {
    for (int i = 1; i <= n; ++i)  rep[i] = i;
    int tot = 0;  // already picked
    int ans = 0;
    int totaledge = total;
    total = 1;
    for (int i = 1; i < totaledge; ++i) {
        int xr = findroot(e[i].u), yr = findroot(e[i].to);
        if (xr != yr) {
            Merge(xr, yr);
            tot++;
            edge(e[i].u, e[i].to, e[i].w, 1);  edge(e[i].to, e[i].u, e[i].w, 1);
        }
    }
}
// end: generate MST

// start: tree decomposition
int dep[maxn], siz[maxn], fa[maxn], son[maxn];
ll w[maxn]; // map the edge weight to the point weight son
void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    son[u] = -1;
    for (int i = hmin[u]; i != 0; i = emin[i].next) {
        int v = emin[i].to;
        if (v != f) {
            w[v] = emin[i].w;
            dfs1(v, u);
            siz[u] += siz[v];
            if (son[u] == -1 || siz[son[u]] < siz[v])  son[u] = v;
        }
    }
}

int clock, id[maxn], top[maxn];
ll wt[maxn];
void dfs2(int x, int topc) {
    top[x] = topc;
    ++clock;
    id[x] = clock;
    wt[clock] = w[x];
    if (son[x] == -1)  return;
    dfs2(son[x], topc);
    for (int i = hmin[x]; i != 0; i = emin[i].next) {
        int v = emin[i].to;
        if (v != fa[x] && v != son[x])  dfs2(v, v);
    }
}
// end: tree decomposition

// start: segment tree -- query max
int max[maxn << 2];

inline void up(int u) { max[u] = std::max(max[u << 1], max[u << 1 | 1]); }

void build(int u, int l, int r) {
    if (l == r) {max[u] = wt[l];  return; }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    up(u);
}

ll query_max(int x, int y, int u, int l, int r) {
    ll ans = LLONG_MIN;
    if (x <= l && r <= y)  return std::max(ans, (ll)max[u]);
    int mid = (l + r) >> 1;
    if (x <= mid) {
        ans = std::max(ans, query_max(x, y, u << 1, l, mid));
    }
    if (mid < y) {
        ans = std::max(ans, query_max(x, y, u << 1 | 1, mid + 1, r));
    }
    return ans;
}
// end: segment tree

ll Q(int x, int y) {
    ll ans = LLONG_MIN;
    for ( ; top[x] != top[y]; ) {
        if (dep[top[x]] < dep[top[y]])  std::swap(x, y);
        ans = std::max(ans, query_max(id[top[x]], id[x], 1, 1, n));
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])  std::swap(x, y);
    // let "x" be LCA
    if (id[x] + 1 <= id[y])  ans = std::max(ans, query_max(id[x] + 1, id[y], 1, 1, n));
    return ans;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edge(u, v, w, 0);  edge(v, u, w, 0);
    }
    std::sort(e + 1, e + total);
    Kruskal();
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    for (int i = 0; i < q; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lld\n", Q(x, y));
    }
    // printf("MST:\n");
    // for (int i = 1; i < total; ++i) {
    //     printf("%d to %d w %lld\n", emin[i].u, emin[i].to, emin[i].w);
    // }
    // printf("rearranged:\n");
    // for (int i = 1; i <= n; ++i) {
    //     printf("id[%d]: %d, top[%d]: %d \n", i, id[i], i, top[i]);
    // }
    // printf("\n");
    // for (int i = 1; i <= n; ++i) {
    //     printf("wt[%d]: %lld\n", id[i], wt[id[i]]);
    // }
    return 0;
}