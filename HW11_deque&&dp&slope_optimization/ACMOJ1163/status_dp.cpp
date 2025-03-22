#include <cstdio>
constexpr int MOD = 1e9 + 7;
int m, n, k, dp[205][1 << 6][1 << 6], pconf[1 << 6], ppconf[1 << 6];  // 当前行与前一行的冲突状态，与前前行的冲突状态
bool broken[205][10];
void pre() {
    for (int mask = 0; mask < (1 << n); ++mask) {  // 枚举当前行状态
        pconf[mask] = ppconf[mask] = 0;
        for (int j = 0; j < n; ++j) {   // 枚举列-1
            if (mask & (1 << j)) {  // 第j+1列有马，那么前一列j-1 or j+3 行不能有马，前前行j or j+2 行不能有马
                if (j >= 2) {pconf[mask] |= 1 << (j - 2); }
                if (j + 2 < n) {pconf[mask] |= 1 << (j + 2); }
                if (j >= 1) {ppconf[mask] |= 1 << (j - 1); }
                if (j+ 1 < n) {ppconf[mask] |= 1 << (j + 1); }
            }
        }
    }
}
int main() {
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        broken[x][y] = true;
    }
    pre();
    // 初始化第一行
    for (int mask = 0; mask < 1 << n; ++mask) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if ((mask & (1 << j)) && broken[1][j + 1]) {  // 马在破损格子上，不行
                ok = false;  break;
            }
        }
        if (ok) dp[1][0][mask] = 1;
    }
    // 转移
    for (int i = 2; i <= m; ++i) {  // 第二行开始转移
        for (int pp = 0; pp < 1 << n; ++pp) {  // 枚举前前行状态
            for (int p = 0; p < 1 << n; ++p) {  // 枚举前行状态
                if (dp[i-1][pp][p] == 0)  continue;
                for (int cur = 0; cur < 1 << n; ++cur) {  // 枚举当前行状态
                    bool ok = true;
                    for (int j = 0; j < n; ++j) {
                        if ((cur & (1 << j)) && broken[i][j + 1]) {
                            ok = false;  break;
                        }
                    }
                    if (!ok) {continue; }  // 确保马不在破损格
                    if ((p & pconf[cur]) || (pp & ppconf[cur])) {  // 前行或者前前行被攻击
                        continue;
                    }
                    // 记录
                    dp[i][p][cur] = (dp[i][p][cur] + dp[i-1][pp][p]) % MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int p = 0; p < 1 << n; ++p) {
        for (int cur = 0; cur < 1 << n; ++cur) {
            ans = (ans + dp[m][p][cur]) % MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*
dp[i][j][k] := 前i行，第i-1行的状态，第i行的状态
*/