#include <cstdio>
#include <cmath>
#include <algorithm>
typedef long long ll;
const int maxn = 5e4+5;
int N, Q, a[maxn], size, cnt[100005];
ll ans[maxn], cur_ans = 0;
struct Query{
    int L, R, idx;
    bool operator <(const Query& other) const {
        bool flg = (L / size) & 1;
        if (flg) {return L / size == other.L / size ? R < other.R : L < other.L; }
        return L / size == other.L / size ? R > other.R : L < other.L;
    }
}q[maxn];
inline void add (int x) {
    cur_ans += 2 * cnt[x] + 1;
    ++cnt[x];
}
void del (int x) {
    cur_ans -= 2 * cnt[x] - 1;
    --cnt[x];
}
int main() {
    scanf("%d%d", &N, &Q);
    size = std::sqrt(N);
    for (int i = 0; i < N; ++i) {scanf("%d", &a[i]); }
    for (int i = 0; i < Q; ++i) {
        scanf("%d%d", &q[i].L, &q[i].R);
        --q[i].L, --q[i].R;
        q[i].idx = i;
    }
    std::sort(q, q + Q);
    int curL = 0, curR = -1;
    for (int i = 0; i < Q; ++i) {
        int L = q[i].L, R = q[i].R;
        while (curL > L)  add(a[--curL]);
        while (curR < R)  add(a[++curR]);
        while (curL < L)  del(a[curL++]);
        while (curR > R)  del(a[curR--]);
        
        ans[q[i].idx] = cur_ans;
    }
    for (int i = 0; i < Q; ++i) printf("%lld\n", ans[i]);
    return 0;
}