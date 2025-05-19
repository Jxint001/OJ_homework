#include <cstdio>
#include <unordered_set>
#include <iostream>
typedef long long ll;
ll q, t, m, n, cnt = 0;
ll num[20], oth[20];
ll uti[20];
std::unordered_set<int> S;
inline void reset() {
    for (int i = 0; i < 20; ++i)  num[i] = 0, oth[i] = 0;
    S.clear();
    //std::cout << "out" << std::endl;
}
inline void pre() {
    ll fill = 1;
    for (int i = 0; i < 20; ++i, fill *= 10) {
        uti[i] = fill;
    }
   // std::cout << "out" << std::endl;
}
inline bool check(ll tobe) {
    int wei = 0;
    ll co = tobe;
    while (tobe / 10 > 0) { wei++; tobe /= 10;}
    for (int j = wei; j >= 1; --j) {
        if (S.find((co/uti[j]) % 10) == S.end()) {
            return false;
        }
    }
    if (S.find(co % 10) == S.end())  return false;
    return true;
}
int main() {
    scanf("%lld%lld", &q, &t);
    pre();
    if (q == 1) {
        for (int i = 0; i < t; ++i) {
            reset();
            scanf("%lld%lld", &m, &n);
             for (int j = 1; j <= m; ++j) {
                int s;
                scanf("%d", &s);
                S.emplace(s);
            }
        }
        ll ans = 0;
        for (ll j = 1; j <= n; ++j) {
            if (check(j))  ++ans;
        }
        printf("%lld\n", ans);
    }
    if (q == 2) {
        for (int i = 0; i < t; ++i) {
            reset();
            scanf("%lld%lld", &m, &n);
             for (int j = 1; j <= m; ++j) {
                int s;
                scanf("%d", &s);
                S.emplace(s);
            }
            for (ll j = n; j > 0; --j) {
                if (check(j)) {
                    //std::cout << "ok" << std::endl;
                    printf("%lld\n", j);
                    break;
                }
            }
        }
    }
    // reset();
    // S.emplace(5);S.emplace(9);
    // check(9999);
    return 0;
}