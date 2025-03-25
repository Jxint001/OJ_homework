#include <iostream>
#include <vector>
#include <utility>
using std::vector, std::pair;
typedef long long ll;
ll n, Q;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    ll n, Q;
    std::cin >> n >> Q;
    vector<vector<pair<int, int>> > tree(n + 3);
    vector<int> xor_path(n + 5, 0);
    bool visited[n + 5];
    for (int i = 0; i < n + 5; ++i)  visited[i] = 0;
    int x, y, w;
    for (int i = 2; i <= n; ++i) {
        std::cin >> x >> y >> w;
        tree[x].push_back({y, w});
        tree[y].push_back({x, w});
    }

    int q[n + 3], head = 0, tail = 0;
    q[tail++] = 1;
    while (head < tail) {
        int cur = q[head++];
        visited[cur] = 1;
        for (auto& [node, v] : tree[cur]) {
            if (!visited[node]) {
                xor_path[node] = v ^ xor_path[cur];
                q[tail++] = node;
            }
        }
    }

    while (Q-- > 0) {
        std::cin >> x >> y;
        std::cout << (xor_path[x] ^ xor_path[y]) << "\n";
    }
}
// 预处理计算每个节点到根节点的异或路径值