#include <algorithm>
#include <cstdio>
#include <cmath>
#include <unordered_map>
constexpr int MAXL = 200005;
int N, M, a[MAXL], pos[MAXL], st[MAXL][32], lg[MAXL];
std::unordered_map<int, int> cnt;

void pre(int n) {
    lg[1] = 0, lg[2] = 1;
    for (int i = 3; i <= n; ++i) {lg[i] = lg[i / 2] + 1; }
    for (int k = 1; k <= lg[n]; ++k) {
        for (int i = 0; i + (1 << k) - 1 < n; ++i) {
            st[i][k] = std::max(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
        }
    }
}
int main() {
    scanf("%d%d", &N, &M);
    scanf("%d", &a[0]);
    cnt.insert({a[0], 0});
    st[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        scanf("%d", &a[i]); 
        if (cnt.find(a[i]) == cnt.end()) {
            pos[i] = pos[i - 1];
            cnt.insert({a[i], i});
        } else {
            pos[i] = std::max(cnt.find(a[i])->second + 1, pos[i - 1]);
            cnt[a[i]] = i;
        }
        st[i][0] = i - pos[i] + 1;
    }
    pre(N);
    int l, r, p, ans;
    while (M > 0) {
        --M;
        scanf("%d%d", &l, &r);

        auto it = std::upper_bound(pos + l, pos + r + 1, l);
        if (it == pos + r + 1) {
            p = r;
        } else {
            p = (int)(it - pos) - 1;
        }

        //p = binary_search(l, r);
        int s = lg[r - p];
        ans = std::max(p - l + 1, 
                p + 1 <= r?std::max(st[p + 1][s], st[r - (1 << s) + 1][s]):1
                );
        printf("%d\n", ans);
    }
    // for (int i = 0; i < N; ++i) {
    //     printf("%d%s%d\n",i, ": ", pos[i]);
    // }
    // printf("%s%d\n", "p: ",p);
    return 0;
}