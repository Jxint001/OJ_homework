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
int main() {
    scanf("%lld%lld", &q, &t);
    pre();
    for (int i = 0; i < t; ++i) {
        scanf("%lld%lld", &m, &n);
        reset();
        if (q == 1) {
            int wei = 1;
            while (n / 10 > 0) { wei++; n /= 10;}
            //std::cout << "ok" << std::endl;
            for (int j = 1; j <= m; ++j) {
                int s;
                scanf("%d", &s);
                S.emplace(s);
            }
            num[1] = m;
            for (int j = 2; j < wei; ++j)  num[j] = num[j-1] * num[1];

            int duan = -1;
            for (int j = wei; j >= 1; --j) {
                if (S.find((n/uti[j]) % 10) == S.end()) {
                    duan = j;  break;
                }
                int cntwei = 0;
                for (int p = 1; p < 10; ++p) {
                    if (S.find(p) != S.end() && p <= (n/uti[j]) % 10)  ++cntwei;
                }
                oth[j] = cntwei;
            }
            
            for (int j = duan - 1; j > 0; --j)  oth[j] = m;
            if (oth[duan] == 0)  num[wei] = 0;
            else  num[wei] = 1;
            for (int j = 1; j <= wei; ++j)  num[wei] *= oth[j];

            ll ans = 0;
            for (int j = 1; j <= wei; ++j) {ans += num[j];}
            printf("%lld\n", ans);
        }
        if (q == 2) {
            for (int j = 1; j <= m; ++j) {
                int s;
                scanf("%d", &s);
                S.emplace(s);
            }
        }
        
    }
    return 0;
}