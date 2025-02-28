#include <algorithm>
#include <iostream>
using std::cin, std::cout, std::endl;
int main() {
    int V, N;
    cin >> V >> N;
    int c[1005], w[1005], f[10005];
    f[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> c[i] >> w[i];
        f[i] = 0;
    }
    for (int i = N + 1; i <= V; ++i) {
        f[i] = 0;
    }
    for (int i = 1; i <= N; ++i) {
        for (int v = c[i]; v <= V; ++v) {
            f[v] = std::max(f[v], f[v - c[i]] + w[i]);
        }
    }
    cout << f[V] << endl;
    return 0;
}