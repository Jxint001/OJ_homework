#include <climits>
#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long ll;

int m, n, pre[2505];
ll dist[2505];
const ll INF = LLONG_MAX >> 2;

struct Edge {
    int u, v, w;
} e[9000];

inline void addEdge(int u, int v, int w, int& edgenum) {
    e[edgenum++] = {u, v, w};
}

int main() {
    scanf("%d%d", &n, &m);
    int edgenum = 1;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w, edgenum);
    }

    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
        addEdge(0, i, 0, edgenum);
    }
    dist[0] = 0;

    for (int it = 1; it <= n; ++it) {
        for (int i = 1; i < edgenum; ++i) {
            int u = e[i].u, v = e[i].v, w = e[i].w;
            if (dist[u] == INF) continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pre[v] = u;
            }
        }
    }

    int c = -1;
    for (int i = 1; i < edgenum; ++i) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (dist[u] == INF) continue;
        if (dist[v] > dist[u] + w) {
            pre[v] = u;
            c = v;
            break;
        }
    }

    if (c == -1) {
        printf("No\n");
    } else {
        for (int i = 0; i < n; ++i) c = pre[c]; // 入环

        std::vector<int> cycle;
        int v = c;
        if (pre[v] == v) {
            printf("Yes\n%d\n%d\n", 1, v);
            return 0;
        }
        do {
            cycle.push_back(v);
            v = pre[v];
        } while (v != c);
    reverse(cycle.begin(), cycle.end());

        printf("Yes\n");
        if (cycle.size() == n + 1) {
            printf("%d\n", n);
            for (int i = 1; i <= n; ++i)  printf("%d ", cycle[i]);
            printf("\n");  return 0;
        }
        printf("%zu\n", cycle.size());
        for (int x : cycle) printf("%d ", x);
        printf("\n");
    }

    return 0;
}