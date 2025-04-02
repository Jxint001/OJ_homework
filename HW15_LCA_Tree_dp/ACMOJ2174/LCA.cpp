// 这个思路寄了
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
typedef long long ll;
const ll maxn = 2e3+5;
struct Edge{
    ll to, next;
}e[maxn << 1];
ll head[maxn << 1], n, size[maxn], deep[maxn], lg[maxn], st[maxn][32];
std::map<std::pair<ll, ll>, ll> adSize;  // 每个节点的邻接子树大小

inline void addEdge(ll u, ll v, ll& edgenum) {
    e[edgenum].to = v;
    e[edgenum].next = head[u];
    head[u] = edgenum++;
}

inline void prelog(ll n) {
    lg[1] = 0;  lg[2] = 1;
    for (ll i = 3; i < n; ++i)  lg[i] = lg[i >> 1] + 1;
}
void dfs(ll u, ll father) {
    st[u][0] = father;
    size[u] = 1;
    deep[u] = deep[father] + 1;
    for (ll i = 1; i <= lg[deep[u]]; ++i) {
        st[u][i] = st[st[u][i-1]][i-1];
    }
    for (ll i = head[u]; i != 0; i = e[i].next) {
        ll v = e[i].to;
        if (v != father) {
            dfs(v, u);
            size[u] += size[v];
            adSize[{u, v}] = size[v];
        }
    }
    adSize[{u, father}] = n - size[u];
}
inline ll retmax(ll u, ll v1, ll v2) {
    ll ret = 0;
    for (ll i = head[u]; i != 0; i = e[i].next) {
        ll x = e[i].to;
        if (x != v1 && x != v2)  ret = std::max(ret, adSize[{u, x}]);
    }
    return ret;
}
ll findLCA(ll u, ll v) {
    if (deep[u] < deep[v])  std::swap(u, v);  // 让u在下面
    // 把u提升到和v同深度
    ll s = deep[u] - deep[v];
    for (ll i = 0; i <= lg[s]; ++i) {
        if (s >> i & 1) {
            u = st[u][i];
        }
    }
    // u,v一起向上走
    if (u == v) return u;
    for (ll i = lg[deep[v]]; i >= 0; --i) {
        if (st[u][i] != st[v][i]) {
            u = st[u][i]; v = st[v][i];
        }
    }
    return st[u][0];
}

ll solve(ll u, ll v) {
    ll lca = findLCA(u, v), ans = 0;
    //prllf("%lld\n", lca);

    std::vector<ll> path;
    while (u != lca) {
        path.push_back(u);
        u = st[u][0];
    }
    std::vector<ll> temp;
    while (v != lca) {
        temp.push_back(v);
        v = st[v][0];
    }
    temp.push_back(v);
    std::reverse(temp.begin(), temp.end());
    path.insert(path.end(), temp.begin(), temp.end());

    // 处理两边
    ans = std::max(ans, n - adSize[{path[0], path[1]}]);
    ans = std::max(ans, n - adSize[{path[path.size() - 1], path[path.size() - 2]}]);
    //prllf("%lld\n", ans);
    for (ll i = 1; i <= ll(path.size()) - 2; ++i) {
        // 处理中间
        ans = std::max(ans, retmax(path[i], path[i-1], path[i+1]) + 1);
    }
    return ans;
}
int main() {
    scanf("%lld", &n);
    ll u, v, edgenum = 1;
    for (ll i = 1; i < n; ++i) {
        scanf("%lld%lld", &u, &v);
        addEdge(u, v, edgenum);
        addEdge(v, u, edgenum);
    }
    prelog(n);
    dfs(1, 0);
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j < i; ++j) {
            ll tmp = solve(i, j);
            ans += tmp;
            //prllf("(%lld, %lld)->%lld\n", i, j, tmp);
        }
    }
    ans *= 2;
    ans += n * n;
    printf("%lld\n", ans);
    return 0;
}