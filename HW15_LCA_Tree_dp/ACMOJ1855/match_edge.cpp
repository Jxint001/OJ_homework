#include <algorithm>
#include <cstdio>
typedef long long ll;
const ll maxn = 5e5+5;
struct Edge{
    int to, next;
}e[maxn << 1];
int n, head[maxn << 1];
inline void addEdge(int u, int v, int& edgenum) {
    e[edgenum].to = v;
    e[edgenum].next = head[u];
    head[u] = edgenum++;
}
ll dp[maxn][2];
void dfs(int u, int fa) {
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {
            dfs(v, u);
        }
    }
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {
            dp[u][0] += std::max(dp[v][0], dp[v][1]);
        }
    }
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {
            dp[u][1] = std::max(dp[u][1], dp[v][0] + 1 + dp[u][0] - std::max(dp[v][0], dp[v][1]));
        }
    }
}
int main() {
    scanf("%d", &n);
    int u, v, edgenum = 1;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v, edgenum);
        addEdge(v, u, edgenum);
    }
    dfs(1, 0);
    printf("%lld\n", std::max(dp[1][0], dp[1][1]));
    return 0;
}

// dp[u][0] := 不选择u时，以u为根的子树中边数最多的匹配
// dp[u][1] := 选择~