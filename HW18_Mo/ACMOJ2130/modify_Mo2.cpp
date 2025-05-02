#include <cstdio>
#include <cmath>
#include <algorithm>
typedef long long ll;
const int maxn = 2e5+5;
int N, Q, M, a[maxn], cnt[1000005];
int size;
ll ans[maxn], cur_ans = 0;
struct Query{
    int L, R, idx, t;
    bool operator <(const Query& other) const {
        if (L / size == other.L / size) {
            return R / size == other.R / size ? t < other.t : R / size < other.R / size;
        } else {
            return L / size < other.L / size;
        }
    }
}q[maxn];
struct Modify {
    int pos, to;
}alter[maxn];
inline void add (int x) {
    cur_ans += !cnt[x]++;
}
inline void del (int x) {
    cur_ans -= !--cnt[x];
}
int main() {
    scanf("%d%d", &N, &M);
    size = pow(N, 2.0 / 3.0);
    for (int i = 0; i < N; ++i) {scanf("%d", &a[i]); }
    Q = 0;
    int modcnt = 0;
    for (int i = 0; i < M; ++i) {
        char opt;
        scanf(" %c", &opt);
        switch (opt) {
            case 'Q':
                scanf("%d%d", &q[Q].L, &q[Q].R);
                --q[Q].L, --q[Q].R;
                q[Q].idx = Q, q[Q].t = modcnt, ++Q;  break;
            case 'C':
                scanf("%d%d", &alter[modcnt].pos, &alter[modcnt].to);
                --alter[modcnt].pos;
                ++modcnt;
                break;
        }
    }
    std::sort(q, q + Q);
    int curL = 0, curR = -1, curT = 0;
    for (int i = 0; i < Q; ++i) {
        int L = q[i].L, R = q[i].R, t = q[i].t;
        while (curL > L)  add(a[--curL]);
        while (curR < R)  add(a[++curR]);
        while (curL < L)  del(a[curL++]);
        while (curR > R)  del(a[curR--]);
        
        while (curT < t) {
            if (curL <= alter[curT].pos && alter[curT].pos <= curR) {
                del(a[alter[curT].pos]);
                add(alter[curT].to);
            }
            std::swap(a[alter[curT].pos], alter[curT].to);
            ++curT;
        }
        while (curT > t) {
            --curT;
            if (curL <= alter[curT].pos && alter[curT].pos <= curR) {
                del(a[alter[curT].pos]);
                add(alter[curT].to);
            }
            std::swap(a[alter[curT].pos], alter[curT].to);
        } 
        ans[q[i].idx] = cur_ans;
    }
    for (int i = 0; i < Q; ++i) printf("%lld\n", ans[i]);
    return 0;
}