#include <climits>
#include <cstdio>
#include <queue>
#include <unordered_map>
#include <algorithm>
char p[25];
int n, k, dp[1005][305], v;
// dp[i][j] := 0~i string, in node j max weighted susm
class AC {
    struct Node {
        Node* next[4] = {nullptr};
        int w = 0, pos = 0;
        Node* fail = nullptr;
    };    

public:
    Node* root = nullptr;
    int num = 1; // number of nodes, including root(empty)
    std::unordered_map<int, Node*> index;
    AC() {
        root = new Node();
        root->pos = 0;
        index[0] = root;
    }
    ~AC() {
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* p = q.front();  q.pop();
            for (int i = 0; i < 4; ++i) {
                if (p && p->next[i])  q.push(p->next[i]);
            }
            delete p;  p = nullptr;
        }
    }
    void insert(const char* s, int v) {
        Node* p = root;
        int i = 0;
        while (s[i] != '\0') {
            int idx = s[i] - 'A';
            if (!p->next[idx]) { p->next[idx] = new Node();  p->next[idx]->pos = num; index[num++] = p->next[idx]; }
            p = p->next[idx];
            ++i;
        }
        p->w += v;
    }

    void build() {
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* p = q.front();  q.pop();
            for (int i = 0; i < 4; ++i) {
                if (p->next[i]) {
                    if (p == root) {
                        p->next[i]->fail = p;
                    } else {
                        Node* f = p->fail;
                        while (f && !f->next[i])  f = f->fail;
                        p->next[i]->fail = f ? f->next[i] : root;
                        p->next[i]->w += p->next[i]->fail->w;
                    }
                    q.push(p->next[i]);
                }
            }
        }
    }
};
int main() {
    scanf("%d%d", &n, &k);
    AC tr;
    while (n-- > 0) {scanf("%s%d", p, &v);  tr.insert(p, v); }
    tr.build();

    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j < tr.num; ++j)
            dp[i][j] = INT_MIN;
    }
    dp[0][0] = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= tr.num; ++j) {
            if (dp[i][j] == INT_MIN)  continue;
            for (int c = 0; c < 4; ++c) {  // enumerate the next char
                auto cur = tr.index[j];
                if (!cur)  continue;
                auto nxt = cur->next[c];
                if (!nxt) {
                    auto tmp = cur->fail;
                    while (tmp && !tmp->next[c])  tmp = tmp->fail;
                    nxt = tmp ? tmp->next[c] : tr.root;
                }
                int pos = nxt->pos;
                dp[i+1][pos] = std::max(dp[i+1][pos], dp[i][j] + nxt->w);
            }
        }
    }
    int max = INT_MIN;
    for (int j = 0; j <= tr.num; ++j) {
        max = std::max(max, dp[k][j]);
    }
    printf("%d\n", max);
}

// 不一定要按照数量*值的方式计算，正确加上每一次出现就好了，不要被思维定势了