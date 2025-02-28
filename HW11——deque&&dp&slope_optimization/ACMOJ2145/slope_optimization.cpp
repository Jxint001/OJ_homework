#include <iostream>
typedef long double lb;
typedef long long ll;
constexpr int MAXL = 5e4+5;

ll t[MAXL], que[MAXL], dp[MAXL], s[MAXL];
int n, C;

inline ll k(ll i) {return i + s[i] - C - 1; }
inline ll k2(ll i) {return k(i) * k(i); }
inline ll x(ll j) {return j + s[j]; }
inline ll y(ll j) {return dp[j] + x(j) * x(j); }

// 这题要维护下凸点集，且新加入的点总是在队尾加入，且检验线的斜率递增
inline lb slope(int i, int j) {return (y(j) - y(i)) / lb(x(j) - x(i)); }

int main() {
    std::cin >> n >> C;
    for (ll i = 1; i <= n; ++i) {std::cin >> t[i];  s[i] = s[i - 1] + t[i]; }
    ll head = 0, tail = 1;
    dp[0] = 0;
    
    for (ll i = 1; i <= n; ++i) {
        // 更新队头
        while (head + 1 < tail && slope(que[head], que[head + 1]) < 2 * k(i)) {++head; }
        // 记录
        ll j = que[head];
        dp[i] = k2(i) + y(j) - 2 * k(i) * x(j);
        // 更新队尾，tail位其实没东西
        while (head + 1 < tail && slope(que[tail - 2], que[tail - 1]) >= slope(que[tail - 1], i)) {--tail; }
        que[tail++] = i;
    }
    std::cout << (long long)dp[n] << std::endl;
    return 0;
}