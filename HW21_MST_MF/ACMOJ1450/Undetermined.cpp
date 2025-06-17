#include <bits/stdc++.h>
using namespace std;
int n, e[105][105], p[105];  // p[j] 是右侧元素 j 对应的左侧元素
bool vis[105];

bool match(int u) {
    //cout << "match" << endl;
    for (int v = 1; v <= n; ++v) {
        if (e[u][v] && !vis[v]) {
            vis[v] = 1;
            if (!p[v] || match(p[v])) {
                p[v] = u;
                return true;
            }
        }
    }
    return false;
}

bool BiMatch() {
    //cout << "Bimatch" << endl;
    for (int u = 1; u <= n; ++u) {
        memset(vis, 0, sizeof(vis));
        if (!match(u)) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j)  scanf("%d", &e[i][j]);
    
    bool ok = BiMatch();
    if (!ok) {
        printf("No\n");  return 0;
    }
    printf("Yes\n");
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", p[j] == i);
        }
        printf("\n");
    }
    return 0;
}