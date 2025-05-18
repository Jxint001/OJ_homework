#include <cstdio>
#include <utility>
const int maxn = 1e5+5;
typedef long long ll;
int n, q, root, a[maxn], head[maxn << 1], total = 1;
struct E{
    int to, next;
}e[maxn << 1];
inline void edge(int u, int v) {
    e[total] = {v, head[u]};
    head[u] = total++;
}

int siz[maxn], dep[maxn], fa[maxn], son[maxn];  // the number of the heavy-son (if ex)
// fill in siz, dep, fa, son
void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    son[u] = -1;
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (v != f) {
            dfs1(v, u);
            if (son[u] == -1 || siz[son[u]] < siz[v])  son[u] = v;
            siz[u] += siz[v];
        }
    }
}

int clock, id[maxn], wt[maxn], top[maxn];  // mark the top vertex of each chain
// rearrange the tree with new number
void dfs2(int x, int topc) {
    ++clock;
    id[x] = clock;
    wt[clock] = a[x];
    top[x] = topc;
    if (son[x] == -1)  return;  // leaf vertex
    dfs2(son[x], topc);
    for (int i = head[x]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (v != fa[x] && v != son[x])  dfs2(v, v);
    }
}


// a[]: old number -> old weight
// id[]: old number -> new number
// wt[]: new number -> new weight
// top[]: old number -> top in chain (old number)

// start: segment tree -- add and query sum
ll add[maxn << 2], sum[maxn << 2];
ll res = 0;  // current query answer

void up(int u) {sum[u]  = sum[u << 1] + sum[u << 1 | 1]; }

void lazy(int u, int val, int len) {
    add[u] += val;
    sum[u] += val * len;
}

void build(int u, int l, int r) {
    if (l == r) {sum[u] = wt[l];  return; }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    up(u);
}

void down(int u, int l_len, int r_len) {
    if (!add[u])  return;
    lazy(u << 1, add[u], l_len);
    lazy(u << 1 | 1, add[u], r_len);
    add[u] = 0;
}

// query [x, y]
void query_sum(int x, int y, int u, int l, int r) {
    if (x <= l && r <= y) {res += sum[u];  return; }
    int mid = (l + r) >> 1;
    down(u, mid - l + 1, r - mid);
    if (x <= mid)  query_sum(x, y, u << 1, l, mid);
    if (mid < y)  query_sum(x, y, u << 1 | 1, mid + 1, r);
}

// add z to [x, y]
void upd_sum(int x, int y, int z, int u, int l, int r) {
    if (x <= l && r <= y) {lazy(u, z, r - l + 1);  return; }
    int mid = (l + r) >> 1;
    down(u, mid - l + 1, r - mid);
    if (x <= mid)  upd_sum(x, y, z, u << 1, l, mid);
    if (mid < y)  upd_sum(x, y, z, u << 1 | 1, mid + 1, r);
    up(u);
}

// end: segment tree
// the following x and y are both old number
void updChain(int x, int y, int z) {
    for ( ; top[x] != top[y]; ) {
        if (dep[top[x]] < dep[top[y]])  std::swap(x, y);
        upd_sum(id[top[x]], id[x], z, 1, 1, n);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])  std::swap(x, y);
    upd_sum(id[x], id[y], z, 1, 1, n);
}

void updSubtree(int x, int z) {upd_sum(id[x], id[x] + siz[x] - 1, z, 1, 1, n); }

inline ll qryChain(int x, int y) {
    ll ans = 0;
    for ( ; top[x] != top[y]; ) {
        if (dep[top[x]] < dep[top[y]])  std::swap(x, y);
        res = 0;
        query_sum(id[top[x]], id[x], 1, 1, n);
        ans += res;
        x = fa[top[x]];  // x jump to the father of the chain top
    }
    if (dep[x] > dep[y])  std::swap(x, y);
    res = 0;
    query_sum(id[x], id[y], 1, 1, n);
    ans += res;
    return ans;
}

inline ll qrySubtree(int x) {
    res = 0;
    query_sum(id[x], id[x] + siz[x] - 1, 1, 1, n);
    return res;
}

int main() {
    scanf("%d%d%d", &n, &q, &root);
    for (int i = 1; i <= n; ++i)  scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge(u, v);
        edge(v, u);
    }
    dfs1(root, 0);
    dfs2(root, root);
    build(1, 1, n);
    for (int i = 0; i < q; ++i) {
        int op;
        scanf("%d", &op);
        switch (op) {
          case 1: {  // add z to weights of nodes on the shortest path x-y
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            updChain(x, y, z);
            break;
          }
          case 2: {  // query the weight sum along the shortest path x-y
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%lld\n", qryChain(x, y));
            break;
          }
          case 3: {  // add z to weights of nodes in x-subtree
            int x, z;
            scanf("%d%d", &x, &z);
            updSubtree(x, z);
            break;
          }
          case 4: {  // query the weight sum in x-subree
            int x;
            scanf("%d", &x);
            printf("%lld\n", qrySubtree(x));
            break;
          }
          default: break;
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     printf("id[%d]: %d, top[%d]: %d \n", i, id[i], i, top[i]);
    // }
    // printf("\n");
    // for (int i = 1; i <= n; ++i) {
    //     printf("wt[%d]: %d\n", id[i], wt[id[i]]);
    // }
    return 0;
}