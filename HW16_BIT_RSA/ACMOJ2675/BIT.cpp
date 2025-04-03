#include <cctype>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
const int maxn = 1e6+5;
struct query{
    int l, r, out;
    bool operator<(const query& other) {
        return r < other.r;
    }
}q[maxn];
int a[maxn], tree[maxn], ans[maxn];
std::unordered_map<int, int> last;

inline void read(int &x){
    char ch=getchar();int f=1;x=0;
    while(!isdigit(ch) && ch^'-') ch=getchar();
    if(ch=='-') f=-1,ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    x*=f;
}

inline void add(int p, int v, int n) {
    while (p <= n) {
        tree[p] += v;
        p += -p & p;
    }
}

inline int Query(int k) {
    int ret = 0;
    while (k > 0) {
        ret += tree[k];
        k -= -k & k;
    }
    return ret;
}

int main() {
    int n;  read(n);
    for (int i = 1; i <= n; ++i)  read(a[i]);
    int m, l, r;  read(m);
    for (int i = 1; i <= m; ++i) {
        read(l);  read(r);
        q[i].l = l, q[i].r = r, q[i].out = i;
    }
    std::sort(q + 1, q + m + 1);
    int idx = 1;
    for (int i = 1; i <= n; ++i) {
        int ocur = last[a[i]];
        if (ocur != 0) {
            add(ocur, -1, n);
        }
        last[a[i]] = i;  add(i, 1, n);
        while (idx <= m && q[idx].r == i) {
            ans[q[idx].out] = Query(i) - Query(q[idx].l - 1);
            ++idx;
        }
    }
    for (int i = 1; i <= m; ++i)  printf("%d\n", ans[i]);
    return 0;
}
// 单点修改+区间查询