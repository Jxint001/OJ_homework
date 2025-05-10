#include <climits>
#include <iostream>
const int maxn = 1e5+3;
long long tot;
int n, k, head[maxn << 1], cnt[maxn];// 点号->边数
bool Del[maxn << 1];  // 边号->是否被删除
struct edge{
    int to, next, w;
}e[maxn << 1];
inline void addedge(int u, int v, int w, int& num) {
    e[num].to = v;
    e[num].w = w;
    e[num].next = head[u];
    head[u] = num++;
    cnt[u]++;
}
void del_min(int u) {
    //std::cout << u << std::endl;
    int to_delete, M = INT_MAX;
    for (int i = head[u]; i != 0; i = e[i].next) {
        //std::cout << e[i].to << std::endl;
        if (M > e[i].w && !Del[i]) {
            to_delete = i;  M = e[i].w;
        }
    }
    Del[to_delete] = 1;
    int v = e[to_delete].to;  cnt[v]--;
    //std::cout << "v: " << v << std::endl;
    for (int i = head[v]; i != 0; i = e[i].next) {
        if (e[i].to == u) {
            Del[i] = 1;
            break;
        }
    }
}
void dfs(int u, int fa) {
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to, w = e[i].w;
        if (v != fa) {
            dfs(v, u);
        }
    }
    if (cnt[u] > k) {
        //std::cout << "? " << std::endl;
        int s = cnt[u] - k;
        for (int i = 0; i < s; ++i) {
            del_min(u);
            cnt[u]--;
        }
    }
}
int main() {
    std::cin >> n >> k;
    int u, v, w, num = 1;
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> u >> v >> w;
        addedge(u, v, w, num);
        addedge(v, u, w, num);
        tot += w;
    }
    dfs(0, -1);
    long long minus = 0;
    for (int i = 1; i < num; ++i) {
        if (Del[i]) {minus += e[i].w; }
    }
    tot -= minus >> 1;
    std::cout << tot << std::endl;
    // for (int i = 1; i < num; ++i) {
    //     std::cout << Del[i] << std::endl;
    // }
    return 0;
}