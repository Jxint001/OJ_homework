#include <climits>
#include <cstdio>
#include <queue>
int n, m, s, t, head[2505], a[2505][2505];
long long dist[2505];
struct cmp {
    bool operator()(int a, int b) const {
        return dist[a] > dist[b];
    }
};
int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        if (a[u][v] == 0 || w < a[u][v]) {
            a[u][v] = w;
            a[v][u] = w;
        }
    }

    for (int i = 0; i <= n; ++i) {dist[i] = LLONG_MAX; }
    dist[s] = 0;

    std::priority_queue<int, std::vector<int>, cmp> Q;
    Q.emplace(s);

    while (!Q.empty()) {
        int u = Q.top();  Q.pop();
        for (int i = 1; i <= n; ++i) {
            if (a[u][i]) {
                if (dist[i] > dist[u] + a[u][i]) {
                    dist[i] = dist[u] + a[u][i];
                    Q.emplace(i);
                }
            }
        }
    }
    printf("%lld\n", dist[t]);
    return 0;
}
// 无负权边