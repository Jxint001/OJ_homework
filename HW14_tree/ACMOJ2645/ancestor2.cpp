#include <cstdio>
#include <vector>
using std::vector;
const int maxn = 1e5+5;
int clock = 0;
void dfs(vector<vector<int> >& tree, vector<int>& timein, vector<int>& timeout, vector<bool>& visit, int u) {
    visit[u] = 1;
    int len = tree[u].size();
    timein[u] = clock++;
    for (int i = 0; i < len; ++i) {
        if (!visit[tree[u][i]]) {
            dfs(tree, timein, timeout, visit, tree[u][i]);
        }
    }
    timeout[u] = clock++;
}
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<vector<int> > tree(n + 3);
    vector<bool> visit(n+3, 0);
    vector<int> timein(n+3, 0);
    vector<int> timeout(n+3, 0);
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(tree, timein, timeout, visit, 1);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &u, &v);
        if (timein[u] <= timein[v] && timeout[u] >= timeout[v]) printf("%d\n", u);
        else if (timein[v] <= timein[u] && timeout[v] >= timeout[u]) printf("%d\n", v);
        else printf("%d\n", -1);
    }
}