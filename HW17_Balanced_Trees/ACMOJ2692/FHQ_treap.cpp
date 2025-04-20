#include <cstdio>
#include <cstdlib>
const int maxn = 1e6+5;
int N, M, root, tot;
struct node {
    int val, key, siz, l, r; // 不需要cnt，FHQ treap认为权值相同的节点是多个节点
}tr[maxn];

inline void pushup(int x) {
    tr[x].siz = tr[tr[x].l].siz + tr[tr[x].r].siz + 1;
}

// 按照size分裂，<=k的是左树，>k的是右树
void split_siz(int u, int k, int &lt, int &rt) {  // 不只是"分"，还有建立树结构，当线段树理解
    if (!u) {
        lt = 0, rt = 0;
        return;
    }
    if (tr[tr[u].l].siz < k) {
        lt = u;
        split_siz(tr[lt].r, k - tr[tr[u].l].siz - 1, tr[lt].r, rt);
    } else {
        rt = u;
        split_siz(tr[rt].l, k, lt, tr[rt].l);
    }
    pushup(u);
}

// 把 left_tree 和 right_tree 拼在一起， 前提是前者所有节点的"val值"都比后者小，可以直接维护BST，再看咋维护heap
int merge(int lt, int rt) {
    if (!lt || !rt) {
        return lt | rt;
    }
    if (tr[lt].key < tr[rt].key) {  // 选择维护min_heap
        tr[lt].r = merge(tr[lt].r, rt);  // 也可以用线段树理解
        pushup(lt);
        return lt;
    } else {
        tr[rt].l = merge(lt, tr[rt].l);
        pushup(rt);
        return rt;
    }
}

// 新建节点
int newNode(int val) {
    tr[++tot] = {val, rand(), 1, 0, 0};
    return tot;
}

// 在pos之后插入val
void Insert(int pos, int val) {
    int lt, rt;
    split_siz(root, pos, lt, rt);
    root = merge(merge(lt, newNode(val)), rt);
}

// 删除第pos个数
void Delete(int pos) {
    int lt, rt, l1, l2;
    split_siz(root, pos - 1, lt, rt);
    // 再把右边的树分裂一下
    split_siz(rt, 1, l1, l2);
    // 再把l1,l2,lt合并（扔掉现在的l1）
    l1 = merge(tr[l1].l, tr[l1].r);
    root = merge(lt, merge(l1, l2));
}

void Print(int node) {
    if (!node)  return;
    Print(tr[node].l);
    printf("%d ", tr[node].val);
    Print(tr[node].r);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        int val;  scanf("%d", &val);
        Insert(i - 1, val);
    }

    for (int i = 1; i <= M; ++i) {
        int opt;  scanf("%d", &opt);
        if (opt == 1) {
            int pos, val;  scanf("%d%d", &pos, &val);
            Insert(pos, val);
        }
        if (opt == 2) {
            int pos;  scanf("%d", &pos);
            Delete(pos);
        }
    }

    Print(root);  printf("\n");
    return 0;
}