#include <climits>
#include <cstdio>
#include <algorithm>

const int maxn = 5005, maxe = 2e5+5;
typedef long long ll;
int n, m, q, head[maxn], total = 1;
struct E{
    int u, to, next;
    ll w;
    bool operator <(const E& other) {
        return w < other.w;
    }
}e[maxe << 1];
inline void edge(int u, int v, ll w) {
    e[total] = {u, v, head[u], w};
    head[u] = total++;
}

int fa[maxn];
ll ans;
int findroot(int x) {
    return fa[x] == x ? x : fa[x] = findroot(fa[x]);
}
void merge(int x, int y) {
    x = findroot(x), y = findroot(y);
    fa[x] = y;
}
void Kruskal() {
    std::sort(e + 1, e + total);
    for (int i = 1; i <= n; ++i)  fa[i] = i;
    for (int i = 1; i < total; ++i) {
        int ur = findroot(e[i].u), vr = findroot(e[i].to);
        if (ur != vr) {
            ans += e[i].w;
            merge(ur, vr);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        edge(u, v, w);  edge(v, u, w);
    }
    
    Kruskal();
    printf("%lld\n", ans);
    return 0;
}