#include <climits>
#include <cstdio>
#include <deque>

typedef long long ll;
const int maxn = 1e6+5;

int m, n, s, t, head[maxn];
ll dist[maxn];

struct Edge {
    ll w, to, next;
}e[maxn << 1];
inline void addEdge(int u, int v, int w, int& edgenum) {
    e[edgenum].to = v;
    e[edgenum].next = head[u];
    e[edgenum].w = w;
    head[u] = edgenum++;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int u, v, w, edgenum = 1;
    for (int i = 0 ;i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w, edgenum);
        addEdge(v, u, w, edgenum);
    }

    for (int i = 0; i <= n; ++i)  dist[i] = LLONG_MAX;
    dist[s] = 0;

    std::deque<int> Q;
    Q.push_back(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop_front();
        for (int i = head[u]; i != 0; i = e[i].next) {
            int v = e[i].to, w = e[i].w;
            long long tmp = dist[u] + w;
            if (dist[v] > tmp) {
                dist[v] = tmp;
                if (w)  Q.push_back(v);
                else  Q.push_front(v);
            }
        }
    }
    printf("%lld\n", dist[t]);
    return 0;
}
// 01bfs可以用双端队列实现（只需要分成前后两层）