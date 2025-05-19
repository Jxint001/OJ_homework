#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int q, m, n, t;
std::vector<std::vector<int> > g(2001);

struct STATE{
    int node, step;
};

int main() {
    scanf("%d%d%d", &q, &m, &n);
    for (int i = 0; i < m; ++i) {
        int k;  scanf("%d", &k);
        int s;  scanf("%d", &s);
        for (int j = 1; j < k; ++j) {
            int t;  scanf("%d", &t);
            g[s].push_back(t);
            g[t].push_back(s);
            s = t;
        }
    }
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int source, target;
        scanf("%d%d", &source, &target);
        std::queue<STATE> q;
        std::vector<bool> vis(n + 1, 0);
        std::vector<int> pre(n, 0);
        q.push({source, 0});
        vis[source] = 1;
        bool ok = 0;
        while (!q.empty()) {
            auto [cur, stp] = q.front();  q.pop();
            if (cur == target) {
                std::vector<int> path;
                for (int now = target; now != 0; now = pre[now]) {
                    path.push_back(now);
                }
                int siz = path.size();
                for (int p = siz - 1; p >= 0; --p) {
                    printf("%d ", path[p]);
                }
                printf("\n");
                ok = 1;
                break;
            }
            std::sort(g[cur].begin(), g[cur].end());
            for (auto nb : g[cur]) {
                if (vis[nb])  continue;
                q.push({nb, stp + 1});
                vis[nb] = 1;
                pre[nb] = cur;
            }
        }
        if (!ok)  printf("-1\n");
    }
    return 0;
}