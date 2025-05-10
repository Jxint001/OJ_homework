#include <cstdio>
#include <vector>
const int maxn = 1e4+5, maxe = 3e4+5;

int n, m, head[maxe], headr[maxe], scc;
bool vis[maxn];
int color[maxn];
std::vector<int> s;

struct Edge {
    int to, next;
}e[maxe], er[maxe];
inline void addEdge(int u, int v, int& edgenum, bool flg) {
    if (!flg){
        e[edgenum].to = v;
        e[edgenum].next = head[u];
        head[u] = edgenum++;
    } else {
        er[edgenum].to = u;
        er[edgenum].next = headr[v];
        headr[v] = edgenum++;
    }
}

void dfs1(int u) {
    vis[u] = true;
    for (int i = headr[u]; i != 0; i = er[i].next) {
        int v = er[i].to;
        if (!vis[v])  dfs1(v);
    }
    s.push_back(u);
}

void dfs2(int u) {
    color[u] = scc;
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (!color[v])  dfs2(v);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v, num = 1, numr = 1;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v, num, 0);
        addEdge(u, v, numr, 1);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])  dfs1(i);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (!color[s[i]]) {
            ++scc;
            dfs2(s[i]);
        }
    }

    // 统计每个scc的出度
    std::vector<int> out(scc + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = head[i]; j != 0; j = e[j].next) {
            int v = e[j].to;
            if (color[i] != color[v])  ++out[color[i]];
        }
    }

    // 统计每个scc大小
    std::vector<int> scc_size(scc + 1, 0);
    for (int i = 1; i <= n; ++i)  ++scc_size[color[i]];

    // 找唯一的sink
    int sink_cnt = 0, ans = 0;
    for (int i = 1; i <= scc; ++i) {
        if (out[i] == 0) {
            ++sink_cnt;
            ans = scc_size[i];
        }
    }
    
    printf("%d\n", sink_cnt == 1 ? ans : 0);
    return 0;
}