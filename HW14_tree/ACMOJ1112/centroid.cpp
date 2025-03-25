#include <cstdio>
#include <vector>
const int maxn = 1e4+5;
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
    dfs(1, tree);
    if (center[1] != 0) {
        if (center[0] < center[1])  printf("%d\n%d\n", center[0], center[1]);
        else  printf("%d\n%d\n", center[1], center[0]);
    } else {
        printf("%d\n", center[0]);
    }
    return 0;
}