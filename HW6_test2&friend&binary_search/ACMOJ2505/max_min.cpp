#include <iostream>
#include <algorithm>
typedef unsigned long long ll;
ll min = 0, max = 0, n, m;
ll a[300005], b[300005];
ll MAX;
ll high, low = 0, ans = 0;
ll need[300005];
bool check(ll x) {
    ll vac = 0, more = 0;
    for (int i = 0; i < n ; ++i) {
        need[i] = std::min((x + a[i] - 1)/a[i], (x + b[i] - 1)/b[i]);
        if (need[i] <= m) {
            vac += m - need[i];
        } else {
            more += (x - (m * std::max(a[i], b[i])) + b[i] - 1) / b[i];
        }
    }
    return vac >= more;
}
int main() {
    
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] > max)  max = a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        if (b[i] > max)  max = b[i];
    }
    MAX = m * max;
    high = MAX;
    while (low <= high) {
        ll x = low + (high - low) / 2;
        if (check(x)) {
            ans = x;
            low = x + 1;
        } else {
            high = x - 1;
        }
    }
    std::cout << ans << std:: endl;
    return 0;
}