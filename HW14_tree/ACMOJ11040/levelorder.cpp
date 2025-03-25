#include <vector>
#include <cstdio>
using std::vector;
int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int> >  tree(n + 3);
    int num;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &num);
        tree[num].push_back(i);
    }

    vector<int> q(n + 3);
    int head = 0, tail = 0;
    q[tail++] = 0;
    printf("%d ", 0);
    while (head < tail) {
        for (auto j : tree[q[head]]) {
            printf("%d ", j);
            q[tail++] = j;
        }
        ++head;
    }
    // printf("%d ", 0);
    // for (int i = 0; i < n; ++i) {
    //     for (auto j : tree[i]) {
    //         printf("%d ", j);
    //     }
    // }
    printf("\n");
    return 0;
}