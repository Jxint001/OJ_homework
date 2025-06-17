#include <bits/stdc++.h>
#include <climits>
using namespace std;
const int maxn = 2e5 + 5, maxm = 1e5 + 5;
int n, m, s, t, k;
vector<vector<int>> g(maxn);
int dist[maxn][2];
bool vis[maxn][2];

void BFS() {
    queue<pair<int, int> > q;
    q.push({s, 0});
    vis[s][0] = 1;  dist[s][0] = 0;
    while (!q.empty()) {
        auto [u, flg] = q.front();  q.pop();
        for (const auto& v : g[u]) {
            if (!flg) {
                if (vis[v][1])  continue;
                if (dist[v][1] > dist[u][0] + 1) {
                    dist[v][1] = dist[u][0] + 1;
                    q.push({v, 1});  vis[v][1] = 1;
                }
            } else {
                if (vis[v][0])  continue;
                if (dist[v][0] > dist[u][1] + 1) {
                    dist[v][0] = dist[u][1] + 1;
                    q.push({v, 0});  vis[v][0] = 1;
                }
            }
        }
    }

    int ans = dist[t][k & 1];
    if (ans <= k)  printf("Yes\n");
    else printf("No\n");
}

int main() {
    scanf("%d%d%d%d%d", &n, &m, &s, &t, &k);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i <= n; ++i) {dist[i][0] = dist[i][1] = INT_MAX; }
    BFS();
    return 0;
}