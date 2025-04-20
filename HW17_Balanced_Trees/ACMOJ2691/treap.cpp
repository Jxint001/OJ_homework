#include <cstdio>
#include <cstdlib>
//#include <deque>
const int maxn = 3e6 + 5;

int M, N, add[maxn], get[maxn], ans[maxn], root, tot;
struct node{
    int val, key, cnt, siz, l, r;
}tree[maxn];

inline void update(int node) {
    tree[node].siz = tree[tree[node].l].siz + tree[tree[node].r].siz + tree[node].cnt;
}
void RotateLeft(int& node) {  // 改变连接关系而不是覆盖值，传引用是为了在insert后update正确的节点和保持正确树结构
    int right = tree[node].r;
    tree[node].r = tree[right].l;
    tree[right].l = node;
    node = right;
    update(tree[node].l);  update(node);
}
void RotateRight(int& node) {
    int left = tree[node].l;
    tree[node].l = tree[left].r;
    tree[left].r = node;
    node = left;
    update(tree[node].r);  update(node);
}
void Insert(int& node, int val) {
    if (!node) {  // 到了一个空位置，不一定是根为0；但只有在空树的情况下root会被这里直接改变
        node = ++tot;
        tree[tot].siz = 1;  tree[tot].cnt = 1;
        tree[tot].val = val;
        tree[tot].key = rand();
        return; 
    }
    if (val == tree[node].val) {tree[node].cnt++;}
    else if (val < tree[node].val) {
        Insert(tree[node].l, val);
        if (tree[node].key < tree[tree[node].l].key)  RotateRight(node);
    } else {
        Insert(tree[node].r, val);
        if (tree[node].key < tree[tree[node].r].key)  RotateLeft(node);
    }
    update(node);
}

// void level_bfs(int node) {
//     std::deque<int> q;
//     q.push_back(node);
//     while (!q.empty()) {
//         int top = q.front();  q.pop_front();
//         printf("%d size: %d\n", tree[top].val, tree[top].siz);
//         if (tree[top].l) {q.push_back(tree[top].l); }
//         if (tree[top].r) {q.push_back(tree[top].r); }
//     }
// }

// void mid_dfs(int node) {
//     if (!node)  return;
//     mid_dfs(tree[node].l);
//     printf("%d\n", tree[node].val);
//     mid_dfs(tree[node].r);
// }
int RankToVal(int node, int rank) {  // 第rank小
    //printf("%d %d\n", node, rank);
    if (!node)  return -1;
    if (tree[tree[node].l].siz >= rank) {return RankToVal(tree[node].l, rank); }
    else if (tree[tree[node].l].siz + tree[node].cnt >= rank) {return tree[node].val; }
    else return RankToVal(tree[node].r, rank - tree[tree[node].l].siz - tree[node].cnt);
}

int main() {
    scanf("%d%d", &M, &N);
    for (int i = 1; i <= M; ++i) {scanf("%d", &add[i]); }
    for (int i = 1; i <= N; ++i) {scanf("%d", &get[i]); }
    
    int k = 1;
    for (int i = 1; i <= M; ++i) {
        Insert(root, add[i]);
        while (i == get[k]) {
            ans[k] = RankToVal(root, k);
            //printf("-----\n");
            ++k;
        }
    }

    for (int i = 1; i <= N; ++i) {printf("%d\n", ans[i]); }
    // level_bfs(root);
    // printf("-----\n");
    // mid_dfs(root);
    // printf("----\n");
    // printf("%d\n", tree[root].val);
    return 0;
}