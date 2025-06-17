#include <bits/stdc++.h>
using namespace std;
const int maxm = 500 * 500 + 10;
int n, m, sw, sb;
vector<int> white, black;
int p[1005];  // p[black] = white;

bool color[1005], vis[1005], visw[1005], visb[1005];
bool matched[1005];
int edgenum = 1, head[1005];
struct e{
    int to, nxt;
}e[maxm << 1];
void adde(int u, int v) {
    e[edgenum] = {v, head[u]};
    head[u] = edgenum++;
}

void dfs(int u, int fa) {
    vis[u] = 1;
    color[u] = color[fa] ^ 1;
    if (color[u])  black.push_back(u);
    else white.push_back(u);
    for (int i = head[u]; i != 0; i = e[i].nxt) {
        int v = e[i].to;
        if (!vis[v]) {dfs(v, u); }
    }
}

bool match(int u) {
    for (int i = head[u]; i != 0; i = e[i].nxt) {
        int v = e[i].to;
        if (!vis[v]) {
            vis[v] = 1;
            if (!p[v] || match(p[v])) {
                p[v] = u;
                return true;
            }
        }
    }
    return false;
}

int BiMatch() {
    int res = 0;
    for (const auto& u : white) {
        memset(vis, 0, sizeof(vis));
        if (match(u)) {++res, matched[u] = 1;}
    }
    return res;
}

void dfs2(int u) {
    visw[u] = 1;
    for (int i = head[u]; i != 0; i = e[i].nxt) {
        int v = e[i].to;
        if (color[v] && p[v] != u && !visb[v]) {
            visb[v] = 1;
            if (p[v] && !visw[p[v]])  dfs2(p[v]);
        }
    }
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adde(u, v);  adde(v, u);
    }
    for (int u = 1; u <= n; ++u) {
        if (!vis[u]) dfs(u, 0);
    }

    int ans = n - BiMatch();
    printf("%d\n", ans);
    for (const auto& i : white) {
        if (!matched[i] && !visw[i])  dfs2(i);
    }
    for (const auto& w : white) {
        if (visw[w])  printf("%d ", w);
    }
    for (const auto& b : black) {
        if (!visb[b])  printf("%d ", b);
    }
    printf("\n");
    return 0;
}