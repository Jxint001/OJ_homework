#include <cstdio>
#include <cstdlib>
#include <utility>
const int maxn = 1e6+5;
int n, m, root, tot;
struct node {
    int val, key, siz, l, r;
    int flip;  // 用于区间翻转的懒标记
}tr[maxn];

inline void up(int x) {
    tr[x].siz = tr[tr[x].l].siz + tr[tr[x].r].siz + 1;
}

inline void down(int x) {
    if (tr[x].flip) {
        std::swap(tr[x].l, tr[x].r);
        if (tr[x].l)  tr[tr[x].l].flip ^= 1;
        if (tr[x].r)  tr[tr[x].r].flip ^= 1;
        tr[x].flip = 0;
    }
}

int newNode(int val) {
    tr[++tot] = {val, rand(), 1, 0, 0};
    return tot;
}

void split_siz(int u, int k, int &lt, int &rt) {  // 不只是"分"，还有建立树结构，当线段树理解
    if (!u) {
        lt = 0, rt = 0;
        return;
    }
    down(u);
    if (tr[tr[u].l].siz < k) {
        lt = u;
        split_siz(tr[lt].r, k - tr[tr[u].l].siz - 1, tr[lt].r, rt);
    } else {
        rt = u;
        split_siz(tr[rt].l, k, lt, tr[rt].l);
    }
    up(u);
}

int merge(int lt, int rt) {
    if (!lt || !rt) {
        return lt | rt;
    }
    down(lt);  down(rt);
    if (tr[lt].key < tr[rt].key) {  // 选择维护min_heap
        tr[lt].r = merge(tr[lt].r, rt);  // 也可以用线段树理解
        up(lt);
        return lt;
    } else {
        tr[rt].l = merge(lt, tr[rt].l);
        up(rt);
        return rt;
    }
}

void Print(int x) {
    if (!x)  return;
    down(x);
    Print(tr[x].l);
    printf("%d ", tr[x].val);
    Print(tr[x].r);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        root = merge(root, newNode(i));
    }

    for (int i = 1; i <= m; ++i) {
        int l, r;  scanf("%d%d", &l, &r);
        int lt, rt, l1, l2;
        split_siz(root, l - 1, lt, rt);
        split_siz(rt, r - l + 1, l1, l2);
        tr[l1].flip ^= 1;
        rt = merge(l1, l2);
        root = merge(lt, rt);
    }

    Print(root);  printf("\n");
    return 0;
}