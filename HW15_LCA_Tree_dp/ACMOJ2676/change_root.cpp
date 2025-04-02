#include <cstdio>
typedef long long ll;
const int maxn = 1e5+5;
struct Edge{
    int to, next;
}e[maxn << 1];
int n, head[maxn << 1], deep[maxn];
ll ans[maxn], size[maxn];

inline void addEdge(int u, int v, int& edgenum) {
    e[edgenum].to = v;
    e[edgenum].next = head[u];
    head[u] = edgenum++;
}

void dfs(int u, int fa) {
    size[u] = 1;
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {
            dfs(v, u);  size[u] += size[v];
        }
    }
}
void dfs2(int u, int fa) {
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {
            ans[v] = ans[u] + n - 2 * size[v];
            dfs2(v, u);
        }
    }
}
int main() {
    scanf("%d", &n);
    int u, v, edgenum = 1;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v, edgenum);
        addEdge(v, u, edgenum);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        ans[1] += size[i];
    }
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) printf("%lld\n", ans[i]);
    return 0;
}