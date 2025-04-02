#include <cstdio>
#include <algorithm>
const int maxn = 205;
struct Edge{
    int to, next;
}e[maxn];
int head[maxn], size[maxn], M, N, dp[maxn][maxn];
inline void addEdge(int u, int v, int& edgenum) {
    e[edgenum].to = v;
    e[edgenum].next = head[u];
    head[u] = edgenum++;
}
void dfs(int u, int fa) {
    size[u] = 1;
    for (int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {
            dfs(v, u);
            // 合并 dp 状态：逆序遍历 u 当前状态，枚举在 v 中选取课程
            for (int j = size[u]; j >= 1; --j) {
                for (int k = 0; k <= size[v] && j + k <= N + 1; ++k) {
                    dp[u][j + k] = std::max(dp[u][j + k], dp[u][j] + dp[v][k]);
                }
            }
            size[u] += size[v];
        }
    }
}
int main() {
    scanf("%d%d", &M, &N);
    for (int i = 0; i <= M; ++i)  head[i] = -1;
    int v, w, edgenum = 1;
    for (int i = 1; i <= M; ++i) {
        scanf("%d%d", &v, &w);
        addEdge(v, i, edgenum);
        dp[i][1] = w;
    }
    dfs(0, -1);
    printf("%d\n", dp[0][N + 1]);
    return 0;
}
// dp[u][k] := 在以u为根的子树中选择k门课时的最大学分
// 0是空节点没有课且必选，最后一共选 N+1 门