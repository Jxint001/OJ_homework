#include <iostream>
using std::cin;
int h[102][102], c[102][102];
long long int dp[102][102];
int n, m;
void find_bigest_sum(int i, int j) {
    if (h[i][j] > h[i+1][j] && h[i][j] > h[i][j+1] && h[i][j] > h[i-1][j] && h[i][j] > h[i][j-1]) {
        return;
    }
    if (h[i+1][j] > h[i][j] && i + 1 <= n && (dp[i+1][j] == -1 || dp[i+1][j] - c[i+1][j] < dp[i][j])) {
        dp[i+1][j] = dp[i][j] + c[i+1][j];
        find_bigest_sum(i+1, j);
    }
    if (h[i][j+1] > h[i][j] && j + 1 <= m && (dp[i][j+1] == -1 || dp[i][j+1] - c[i][j+1] < dp[i][j])) {
        dp[i][j+1] = dp[i][j] + c[i][j+1];
        find_bigest_sum(i, j+1);
    }
    if (h[i-1][j] > h[i][j] && i - 1 >= 1 && (dp[i-1][j] == -1 || dp[i-1][j] - c[i-1][j] < dp[i][j])) {
        dp[i-1][j] = dp[i][j] + c[i-1][j];
        find_bigest_sum(i-1, j);
    }
    if (h[i][j-1] > h[i][j] && j - 1 >= 1 && (dp[i][j-1] == -1 || dp[i][j-1] - c[i][j-1] < dp[i][j])) { 
        dp[i][j-1] = dp[i][j] + c[i][j-1];
        find_bigest_sum(i, j-1);
    }
    return;
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
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            
            if ((h[i][j] < h[i+1][j] || (h[i][j] > h[i+1][j] && h[i+1][j] == -1))&& 
                (h[i][j] < h[i][j+1] || (h[i][j] > h[i][j+1] && h[i][j+1] == -1)) && 
                (h[i][j] < h[i-1][j] || (h[i][j] > h[i-1][j] && h[i-1][j] == -1)) && 
                (h[i][j] < h[i][j-1] || (h[i][j] > h[i][j-1] && h[i][j-1] == -1)))
            {
                for (int e = 1; e <= n; ++e) 
                    for (int r = 1; r <= m; ++r)  dp[e][r] = -1; 
                dp[i][j] = c[i][j];
                find_bigest_sum(i, j);
                for (int e = 1; e <= n; ++e) {
                    for (int r = 1; r <= m; ++r) {
                        if (ans < dp[e][r])  ans = dp[e][r];
                    }
                }
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}