#include <climits>
#include <cstdio>
#include <algorithm>

int n, k;
const int maxn = 5e3 + 5;
struct data{
    int a, b;
    bool operator < (const data& other) {
        return this->b < other.b;
    }
}data[maxn];
long long dp[maxn][maxn];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &data[i].a, &data[i].b);
    }
    std::sort(data + 1, data + n + 1);

    // 最小b值选谁
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = std::max(dp[i-1][1], (long long)data[i].a + data[i].b);
    }

    for (int i = 2; i <= k; ++i) {
        for (int j = i; j <= n; ++j) {
            dp[j][i] = std::max(dp[j-1][i], dp[j-1][i-1] + data[j].a);
        }
    }

    // 最后一个选的不是i那就说明候选值一定不是最大，没事
    long long ans = LONG_LONG_MIN;
    for (int i = k; i <= n; ++i) {
        ans = std::max(ans, dp[i][k] - data[i].b);
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 0; j <= k; ++j) {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%lld\n", ans);
}