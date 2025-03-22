#include <cstdio>
#include <queue>
#include <unordered_map>
#include <vector>
const int maxs = 1e6+5, maxp = 1e5+5;
char s[maxs], p[maxp];
int m;
class AC {
    struct Node {
        Node* next[26] = {nullptr};
        int cnt = 0, sum = 0;
        Node* fail = nullptr;
    };
    Node* root = nullptr;
    std::vector<Node*> end_notes;
    std::unordered_map<Node*, std::vector<Node*> > fail_tree;

public:
    AC() {
        root = new Node();
    }
    ~AC() {
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* p = q.front();  q.pop();
            for (int i = 0; i < 26; ++i) {
                if (p && p->next[i])  q.push(p->next[i]);
            }
            delete p;  p = nullptr;
        }
    }
    void insert(const char* s) {
        Node* p = root;
        int i = 0;
        while (s[i] != '\0') {
            int idx = s[i] - 'a';
            if (!p->next[idx])  p->next[idx] = new Node();
            p = p->next[idx];
            ++i;
        }
        end_notes.push_back(p);
    }

    void build() {
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* p = q.front();  q.pop();
            for (int i = 0; i < 26; ++i) {
                if (p->next[i]) {
                    if (p == root) {
                        p->next[i]->fail = p;
                    } else {
                        Node* f = p->fail;
                        while (f && !f->next[i])  f = f->fail;
                        p->next[i]->fail = f? f->next[i]: root;
                    }
                    fail_tree[p->next[i]->fail].push_back(p->next[i]);
                    q.push(p->next[i]);
                }
            }
        }
    }

    void query(const char* s) {
        int i = 0;
        Node *p = root;
        while (s[i] != '\0') {
            int idx = s[i] - 'a';
            while (p && !p->next[idx])  p = p->fail;
            p = p? p->next[idx] : root;
            ++(p->cnt);
            ++i;
        }
    }

    void sum_subtree(Node* word) {
        word->sum = word->cnt;
        for (auto u : fail_tree[word]) {
            sum_subtree(u);
            word->sum += u->sum;
        }
    }

    void report() {
        sum_subtree(root);
        for (auto u : end_notes) {
            printf("%d\n", u->sum);
        }
    }
};
int main() {
    scanf("%s", s);
    scanf("%d", &m);
    AC tr;
    while (m-- > 0) {scanf("%s", p);  tr.insert(p); }
    tr.build();
    tr.query(s);
    tr.report();
}