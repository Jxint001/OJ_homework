#include <climits>
#include <cstdio>
#include <queue>
const int maxn = 205;
typedef long long ll;
int n, m, head[maxn], tot = 0;
struct Edge{
    int u, v, c, nxt;
    ll fl;
}e[maxn << 1];
inline void edge(int u, int v, int c) {
    e[tot] = {u, v, c, head[u], 0};
    head[u] = tot++;
}

int prevv[maxn], preve[maxn];
ll maxflow() {
    ll flow = 0;
    int s = 1, t = n;
    for (;;) {
        for (int i = 0; i <= n; ++i) {
            prevv[i] = -1;
        }
        std::queue<int> q;
        q.push(s);  prevv[s] = 0;
        // BFS 找通路
        for (; !q.empty() && prevv[t] == -1;) {
            int u = q.front();  q.pop();
            for (int i = head[u]; i != -1; i = e[i].nxt) {
                int v = e[i].v;
                if (prevv[v] == -1 && e[i].fl < e[i].c) {
                    prevv[v] = u;
                    preve[v] = i;
                    q.push(v);
                }
            }
        }
        // 从 s 到不了 t 了
        if (prevv[t] == -1)  break;
        // 找流增量
        ll aug = LLONG_MAX;
        for (int nd = t; nd != s; nd = prevv[nd]) {
            int i = preve[nd];
            aug = std::min(aug, e[i].c - e[i].fl);
        }
        flow += aug;
        // 更新残量图
        for (int nd = t; nd != s; nd = prevv[nd]) {
            int i = preve[nd];
            e[i].c -= aug;
            e[i ^ 1].c += aug;
        }
    }
    return flow;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i)  head[i] = -1;
    for (int i = 0, u, v, c; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &c);
        edge(u, v, c);  edge(v, u, 0);
    }
    printf("%lld\n", maxflow());
    return 0;
}