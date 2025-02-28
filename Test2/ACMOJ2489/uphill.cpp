#include <iostream>
using std::cin, std::cout, std::endl, std::max;
int N, M, map[1003][1003],ans = 0, dp[1003][1003];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool in(int a, int b) {
    return (1 <= a && a <= N) && (1 <= b && b <= M);
}
int len = 1;
void dfs(int x, int y) {
    if (dp[x][y] != -1)  return;
    int tpx, tpy;
    dp[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        tpx = x + dir[i][0];
        tpy = y + dir[i][1];
        if (in(tpx, tpy) && map[tpx][tpy] > map[x][y]) {
            ++len;
            if (dp[tpx][tpy] == -1) {
                dfs(tpx, tpy);
            }
            dp[x][y] = max(dp[x][y], dp[tpx][tpy] + 1);
            --len;
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (dp[i][j] == -1)  dfs(i, j);
            if (dp[i][j] > ans)  ans = dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}