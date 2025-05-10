#include <cstdio>
#include <vector>
const int maxe = 5e5+5, maxn = 2e4+5;

int n, m, dfn[maxn], low[maxn], head[maxe << 1];
int stack[maxe], idx, top;
int bcc;
std::vector<int> ans[maxn];

struct Edge {
    int to, next;
}e[maxe << 1];
inline void addEdge(int u, int v, int& edgenum) {
    e[edgenum].to = v;
    e[edgenum].next = head[u];
    head[u] = edgenum++;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

inline void tarjan(int u, int fa) {
    int son = 0;
    low[u] = dfn[u] = ++idx;
    stack[++top] = u;
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (!dfn[v]) {
            ++son;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            // 找到了割点
            if (low[v] >= dfn[u]) {
                ++bcc;
                while (stack[top + 1] != v) {
                    ans[bcc].push_back(stack[top--]);
                }
                ans[bcc].push_back(u);
            }
        } else if (v != fa) { // 不能顺着dfs树往上走
            low[u] = min(low[u], dfn[v]);  // 默认两个节点之间只有0/1条边？并不是
        }
    }
    if (!fa && !son) {
        ans[++bcc].push_back(u);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int edgenum = 1, u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v, edgenum);
        addEdge(v, u, edgenum);
    }

    for (int i = 1; i <= n; ++i) {
        if (dfn[i] != 0)  continue;
        top = 0;
        tarjan(i, 0);
    }
    printf("%d\n", bcc);
    for (int i = 1; i <= bcc; ++i) {
        int s = ans[i].size();
        printf("%d ", s);
        for (int j = 0; j < s; ++j)  printf("%d ", ans[i][j]);
        printf("\n");
    }
    // for (int i = 1; i <= n; ++i) {
    //     printf("dfn[%d]: %d, low[%d]: %d\n", i, dfn[i], i, low[i]);
    // }
    
    return 0;
}