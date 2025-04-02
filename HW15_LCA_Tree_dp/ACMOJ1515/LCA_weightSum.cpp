#include <cstdio>
#include <utility>
typedef long long ll;
const ll maxn = 1e5+5;
ll N, M, head[maxn << 1], deep[maxn], st[maxn][32], cost[maxn][32], lg[maxn];
struct Edge {
    ll w, to, next;
}e[maxn << 1];
inline void addEdge(ll u, ll v, ll w, ll& edgenum) {
    e[edgenum].to = v;
    e[edgenum].next = head[u];
    e[edgenum].w = w;
    head[u] = edgenum++;
}
inline void prelog(ll n) {
    lg[1] = 0;  lg[2] = 1;
    for (ll i = 3; i < n; ++i)  lg[i] = lg[i >> 1] + 1;
}
void dfs(ll u, ll fa) {
    st[u][0] = fa;
    deep[u] = deep[fa] + 1;
    for (ll i = 1; i <= lg[deep[u]]; ++i) {
        st[u][i] = st[st[u][i-1]][i-1];
        cost[u][i] = cost[u][i-1] + cost[st[u][i-1]][i-1];
    }

    for (ll i = head[u]; i != 0; i = e[i].next) {
        ll v = e[i].to, w = e[i].w;
        if (v != fa) {
            cost[v][0] = w;
            dfs(v, u);
        }
    }
}
ll LCA(ll u, ll v) {
    ll ans = 0;
    if (deep[u] < deep[v])  std::swap(u, v);  // 让u在下面
    // 把u提升到和v同深度
    ll s = deep[u] - deep[v];
    for (ll i = 0; i <= lg[s]; ++i) {
        if (s >> i & 1ll) {
            ans += cost[u][i];
            u = st[u][i];
        }
    }
    // u,v一起向上走
    if (u == v) return ans;
    for (ll i = lg[deep[v]]; i >= 0; --i) {
        if (st[u][i] != st[v][i]) {
            ans += cost[u][i] + cost[v][i];
            u = st[u][i]; v = st[v][i];
        }
    }
    ans += cost[u][0] + cost[v][0];
    return ans;
}
int main() {
    scanf("%lld", &N);
    ll u, v, w, edgenum = 1;
    for (ll i = 0; i < N-1; ++i) {
        scanf("%lld%lld%lld", &u, &v, &w);
        addEdge(u, v, w, edgenum);
        addEdge(v, u, w, edgenum);
    }
    prelog(N);
    dfs(1, 0);
    scanf("%lld", &M);
    for (ll i = 0; i < M; ++i) {
        scanf("%lld%lld", &u, &v);
        printf("%lld\n", LCA(u, v));
    }
    return 0;
}