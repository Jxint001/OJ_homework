#include <cstdio>
#include <utility>
typedef long long ll;
const int maxn = 2e5+5;
ll c[maxn];
struct Edge{
    int to, next;
}e[maxn << 1];
int n, q, head[maxn<<1], lg[maxn], st[maxn][32], deep[maxn];
ll diff[maxn], ans[maxn], add[maxn];
inline void prelog(int n) {
    lg[1] = 0;  lg[2] = 1;
    for (ll i = 3; i < n; ++i)  lg[i] = lg[i >> 1] + 1;
}
inline void addEdge(int u, int v, int& edgenum) {
    e[edgenum].to = v;
    e[edgenum].next = head[u];
    head[u] = edgenum++;
}

void dfs(int u, int fa) {
    st[u][0] = fa;
    deep[u] = deep[fa] + 1;
    for (ll i = 1; i <= lg[deep[u]]; ++i) {
        st[u][i] = st[st[u][i-1]][i-1];
    }
    for (ll i = head[u]; i != 0; i = e[i].next) {
        ll v = e[i].to;
        if (v != fa)  dfs(v, u);
    }
}

int findLCA(int u, int v) {
    if (deep[u] < deep[v])  std::swap(u, v);  // 让u在下面
    // 把u提升到和v同深度
    int s = deep[u] - deep[v];
    for (int i = 0; i <= lg[s]; ++i) {
        if (s >> i & 1) {
            u = st[u][i];
        }
    }
    // u,v一起向上走
    if (u == v) return u;
    for (int i = lg[deep[v]]; i >= 0; --i) {
        if (st[u][i] != st[v][i]) {
            u = st[u][i]; v = st[v][i];
        }
    }
    return st[u][0];
}

void op1(int u, int v, int c) {
    diff[u] += c,  diff[v] += c;
    int lca = findLCA(u, v);
    diff[lca] -= c;
    if (lca != 1) {
        diff[st[lca][0]] -= c;
    }
}

inline void op2(int u, int c) {
    add[u] += c;
}

void getans(int u, int fa) {
    add[u] += add[fa];
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {
            getans(v, u);
            diff[u] += diff[v];
        }
    }
    ans[u] = diff[u] + add[u];
}
int main() {
    scanf("%d%d", &n, &q);
    int u, v, edgenum = 1, flag, c;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v, edgenum);
        addEdge(v, u, edgenum);
    }
    prelog(n);
    dfs(1, 0);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &flag);
        if (flag == 1) {
            scanf("%d%d%d", &u, &v, &c);
            op1(u, v, c);
        }
        if (flag == 2) {
            scanf("%d%d", &u, &c);
            op2(u, c);
        }
    }
    getans(1, 0);
    for (int i = 1; i <= n; ++i) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
    return 0;
}