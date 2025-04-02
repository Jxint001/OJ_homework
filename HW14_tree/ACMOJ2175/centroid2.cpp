#include <cstdio>
#include <vector>
const int maxn = 1e5+5;
int n, size[maxn], weight[maxn], center[2];
bool visited[maxn];

void dfs(int cur, std::vector<std::vector<int> > & tree) {
    size[cur] = 1;
    weight[cur] = 0;
    visited[cur] = 1;
    for (int i = 0; i < tree[cur].size(); ++i) {
        if (!visited[tree[cur][i]]) {
            dfs(tree[cur][i], tree);
            int subtree_size = size[tree[cur][i]];
            size[cur] += subtree_size;
            weight[cur] = std::max(weight[cur], subtree_size);
        }
    }
    weight[cur] = std::max(weight[cur], n - size[cur]);
    if (weight[cur] <= n >> 1) {
        center[center[0] != 0] = cur;
    }
}

int main() {
    scanf("%d", &n);
    int x, y;
    std::vector<std::vector<int> > tree(n + 3);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    // 只有n是偶数才可能有两个重心
    if (n % 2) {
        printf("%d %d\n", x, y);
        printf("%d %d\n", x, y);
        return 0;
    }

    dfs(1, tree);
    if (center[1] != 0) {
        if (tree[center[0]].size() > 1) {
            int move = 0;
            for (auto u : tree[center[0]]) {
                if (u != center[1]) {
                    move = u;  break;
                }
            }
            printf("%d %d\n", center[0], move);
            printf("%d %d\n", center[1], move);
            return 0;
        }
        if (tree[center[1]].size() > 1) {
            int move = 0;
            for (auto u : tree[center[1]]) {
                if (u != center[0]) {
                    move = u;  break;
                }
            }
            printf("%d %d\n", center[1], move);
            printf("%d %d\n", center[0], move);
        }
    } else {
        printf("%d %d\n", x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}