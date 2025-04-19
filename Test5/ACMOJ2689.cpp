#include <cstdio>
#include <utility>
int n, q;
const int maxn = 1e5+5;
struct edge{
    int to, next;
}e[maxn << 1];
int head[maxn << 1], deep[maxn], st[maxn][32], lg[maxn];
inline void adde(int u, int v, int& num) {
    e[num].to = v;
    e[num].next = head[u];
    head[u] = num++;
}
inline void prelog(int n) {
    lg[1] = 0;  lg[2] = 1;
    for (int i = 3; i <= n; ++i)  lg[i] = lg[i >> 1] + 1;
}
void dfs(int u, int fa) {
   // printf("dfs\n");
    deep[u] = deep[fa] + 1;
    st[u][0] = fa;
    for (int i = 1; i <= lg[deep[u]]; ++i) {
        st[u][i] = st[st[u][i-1]][i-1];
    }
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {dfs(v, u);}
    }
}
int LCA(int u, int v) {
    if (deep[u] < deep[v])  std::swap(u, v);

    int s = deep[u] - deep[v];
    //printf("logs: %d\n", lg[s]);
    for (int i = 0; i <= lg[s]; ++i) {
        if (s >> i & 1)  u = st[u][i];
    }

    if (u == v)  return u;
    //printf("deep: %d %d\n", deep[u], deep[v]);

    int k = lg[deep[u]];
    for (int i = k; i >= 0; --i) {
        if (st[u][i] != st[v][i]) {
            u = st[u][i]; v = st[v][i];
        }
    }
    if (u != 1)  return st[u][0];
    return u;
}
int main() {
    scanf("%d%d", &n, &q);
    int num = 1, u, v, w;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        adde(u, v, num);
        adde(v, u, num);
    }
    prelog(n);
    dfs(1, 0);
    for (int i = 1; i <= q; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        if (deep[u] < deep[w])  std::swap(u, w);
        if (deep[v] < deep[w])  std::swap(v, w);
        int l1 = LCA(u, v);
        //printf("%d\n", l1);
        if (l1 == w || l1 == u || l1 == v) {printf("Yes\n"); continue;}
        
        if (deep[l1] >= deep[w]) {
            printf("No\n");
        } else {
            int l2 = LCA(u, w);  int l3 = LCA(v, w);
            if (l2 == w || l3 == w)  printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}