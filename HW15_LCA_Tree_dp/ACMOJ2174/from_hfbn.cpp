// 本思路来自皇甫泊宁同学
#include <cstdio>
const int maxn = 2005;
struct Edge{
    int to, next;
}e[maxn<<1];
int n, head[maxn<<1], size[maxn];
long long f[maxn][maxn];

inline void addEdge(int u, int v, int& edgenum) {
    e[edgenum].to = v;
    e[edgenum].next = head[u];
    head[u] = edgenum++;
}

// 记录每个节点的子树大小
void dfs1(int u, int fa) {
    size[u] = 1;
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {
            dfs1(v, u);  size[u] += size[v];
        }
    }
}

void dfs2(int root, int u, int fa, int max) {
    int cur;
    cur = size[fa] - size[u];
    max = cur > max ? cur : max;
    f[root][u] = max > size[u] ? max : size[u];
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {
            dfs2(root, v, u, max);
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
    // 遍历u，以u为根节点
    for (u = 1; u <= n; ++u) {
        // 填写子树大小
        dfs1(u, 0);  size[0] = n;
        // 填写f(u, v)
        dfs2(u, u, 0, 0);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            //printf("f(%d, %d) = %lld\n", i, j, f[i][j]);
            ans += f[i][j];
        }
    }
    printf("%lld\n", ans);
    return 0;
}