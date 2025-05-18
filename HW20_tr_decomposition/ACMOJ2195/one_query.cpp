#include <cstdio>
const int maxn = 1e6+5;
const long long MOD = 202404;
typedef long long ll;
int n, a[maxn], head[maxn << 1], total = 1;
struct E{
    int to, next;
}e[maxn << 1];
inline void edge(int u, int v) {
    e[total] = {v, head[u]};
    head[u] = total++;
}

int dep[maxn], fa[maxn];
void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (v != f) {
            dfs1(v, u);
        }
    }
}

bool isAnc[maxn];
int F[maxn];  // F[u] := dep[LCA(u, z)]
ll pre[maxn];  // presum of F[]
void DFS(int u, int cur) {  // cur is the LCA candidate
    //printf("DFS(%d, %d)\n", u, cur);
    if (isAnc[u]) {
        //printf("changed\n");
        cur = u;
    }
    F[u] = dep[cur];
    for (int i = head[u]; i != 0; i = e[i].next) {
        int v = e[i].to;
        if (v != fa[u])  DFS(v, cur);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge(u, v);  edge(v, u);
    }
    int l, r, z;
    scanf("%d%d%d", &l, &r, &z);
    // 1 is root
    dfs1(1, 0);
    for (; z != 0; z = fa[z])  isAnc[z] = true;
    DFS(1, 0);
    for (int i = 1; i <= n; ++i)  pre[i] = (pre[i-1] + F[i]) % MOD;
    printf("%lld\n", (pre[r] - pre[l-1] + MOD) % MOD);
    // printf("dep:\n");
    // for (int i = 1; i <= n; ++i) {printf("dep[%d]: %d\n", i, dep[i]);}
    // printf("F:\n");
    // for (int i = 1; i <= n; ++i) {printf("F[%d]: %d\n", i, F[i]); }
    // printf("ancestor:\n");
    // for (int i = 1; i <= n; ++i) {printf("isAnc[%d]: %d\n", i, isAnc[i]); }
    return 0;
}