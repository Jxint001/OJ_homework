#include <iostream>
#include <algorithm>
using std::cin, std::max;
int h[102][102], c[102][102], d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
long long int dp[102][102];
int n, m;
void dfs(int i, int j) {
    if (dp[i][j] != -1)  return;
    dp[i][j] = c[i][j];
    for (int k = 0; k < 4; ++k) {
        int x = i + d[k][0], y = j + d[k][1];
        if (h[x][y] != -1 && h[x][y] > h[i][j]) {
            if (dp[x][y] == -1)  dfs(x, y);
            dp[i][j] = max(dp[i][j], dp[x][y] + c[i][j]);
        }
    }
}
int main() {
    int i, j;
    long long int ans = 0;
    cin >> n >> m;
    for (i = 0; i <= n + 1; ++i) {
        for (j = 0; j <= m + 1; ++j) {
            if (1 <= i && i <= n && 1 <= j && j <= m)  cin >> h[i][j];
            else h[i][j] = -1;
        }
    }
    for (i = 0; i <= n + 1; ++i) {
        for (j = 0; j <= m + 1; ++j) {
            if (1 <= i && i <= n && 1 <= j && j <= m)  cin >> c[i][j];
            else c[i][j] = -1;
        }
    }
    for (int e = 1; e <= n; ++e) 
        for (int r = 1; r <= m; ++r)  dp[e][r] = -1;
    for (i = 0; i <= n + 1; ++i) {
        for (j = 0; j <= m + 1; ++j) {
            if (dp[i][j] == -1)  dfs(i, j);
            if (ans < dp[i][j])  ans = dp[i][j];
        }
    }
    std::cout << ans << std::endl;
    return 0;
}