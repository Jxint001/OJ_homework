#include <cstdio>
#include <algorithm>
using namespace std;
 
const int maxn = 5e4 + 5;
 
struct Node {
    int max, lmax, rmax;
} tree[maxn << 2];
 
// lazy[i] = -1 无延迟标记，0 表示区间全占用，1 表示区间全空闲
int lazy[maxn << 2];
int N, M;
 
void up(int i, int l, int r) {
    int mid = (l + r) >> 1;
    tree[i].lmax = tree[i << 1].lmax;
    if(tree[i << 1].lmax == mid - l + 1)
        tree[i].lmax += tree[i << 1 | 1].lmax;

    tree[i].rmax = tree[i << 1 | 1].rmax;
    if(tree[i << 1 | 1].rmax == r - mid)
        tree[i].rmax += tree[i << 1].rmax;

    tree[i].max = max({tree[i << 1].max, tree[i << 1 | 1].max, tree[i << 1].rmax + tree[i << 1 | 1].lmax});
}

void pushDown(int i, int l, int r) {
    if(lazy[i] != -1) {
        int mid = (l + r) >> 1;
        lazy[i << 1] = lazy[i << 1 | 1] = lazy[i];
        if(lazy[i] == 1) { // 全空闲
            tree[i << 1].lmax = tree[i << 1].rmax = tree[i << 1].max = mid - l + 1;
            tree[i << 1 | 1].lmax = tree[i << 1 | 1].rmax = tree[i << 1 | 1].max = r - mid;
        } else { // 全占用
            tree[i << 1].lmax = tree[i << 1].rmax = tree[i << 1].max = 0;
            tree[i << 1 | 1].lmax = tree[i << 1 | 1].rmax = tree[i << 1 | 1].max = 0;
        }
        lazy[i] = -1;
    }
}
 
void build(int l, int r, int i) {
    lazy[i] = -1;
    if(l == r) {
        tree[i].lmax = tree[i].rmax = tree[i].max = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, i << 1);
    build(mid + 1, r, i << 1 | 1);
    up(i, l, r);
}
 
// 更新区间 [x, y]，setVal = 1 表示置为空闲，setVal = 0 表示置为占用
void update(int x, int y, int l, int r, int i, int setVal) {
    if(x <= l && r <= y) {
        lazy[i] = setVal;
        if(setVal == 1) {
            tree[i].lmax = tree[i].rmax = tree[i].max = r - l + 1;
        } else {
            tree[i].lmax = tree[i].rmax = tree[i].max = 0;
        }
        return;
    }
    pushDown(i, l, r);
    int mid = (l + r) >> 1;
    if(x <= mid) update(x, y, l, mid, i << 1, setVal);
    if(y > mid) update(x, y, mid + 1, r, i << 1 | 1, setVal);
    up(i, l, r);
}
 
int query(int d, int l, int r, int i) {
    if(l == r) return l;
    pushDown(i, l, r);
    int mid = (l + r) >> 1;
    if(tree[i << 1].max >= d) return query(d, l, mid, i << 1);
    if(tree[i << 1].rmax + tree[i << 1 | 1].lmax >= d)
        return mid - tree[i << 1].rmax + 1;
    return query(d, mid + 1, r, i << 1 | 1);
}
 
int main(){
    scanf("%d%d", &N, &M);
    build(1, N, 1);
    while(M--) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int d;
            scanf("%d", &d);
            if(tree[1].max < d) {
                printf("0\n");
            } else {
                int pos = query(d, 1, N, 1);
                printf("%d\n", pos);
                update(pos, pos + d - 1, 1, N, 1, 0);  // 占用这些房间
            }
        } else {
            int x, y;
            scanf("%d%d", &x, &y);
            update(x, x + y - 1, 1, N, 1, 1);  // 退房，设置为空闲
        }
    }
    return 0;
}
