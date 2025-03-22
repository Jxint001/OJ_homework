#include <cstdio>
#include <queue>
#include <unordered_map>
const int maxp = 3e4+5;
char p[maxp];
int n;
class AC {
    struct Node {
        Node* next[2] = {nullptr};
        int cnt = 0, sum = 0;
        Node* fail = nullptr;
        bool ok = true;  // 禁用标志，true代表可以访问这个节点
    };
    enum status {UN, ING, ED};
    std::unordered_map<Node*, status> STATUS;
    

public:
    Node* root = nullptr;
    AC() {
        root = new Node();
    }
    ~AC() {
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* p = q.front();  q.pop();
            for (int i = 0; i < 2; ++i) {
                if (p && p->next[i])  q.push(p->next[i]);
            }
            delete p;  p = nullptr;
        }
    }
    void insert(const char* s) {
        Node* p = root;
        int i = 0;
        while (s[i] != '\0') {
            int idx = s[i] - '0';
            if (!p->next[idx])  p->next[idx] = new Node();
            p = p->next[idx];
            ++i;
        }
        p->ok = false;
    }

    void build() {
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* p = q.front();  q.pop();
            for (int i = 0; i < 2; ++i) {
                if (p->next[i]) {
                    if (p == root) {
                        p->next[i]->fail = p;
                    } else {
                        Node* f = p->fail;
                        while (f && !f->next[i])  f = f->fail;
                        p->next[i]->fail = f? f->next[i]: root;
                    }
                    if (!p->next[i]->fail->ok)  p->next[i]->ok = false;  // 从fail树的父向子传递禁用标志
                    q.push(p->next[i]);
                }
            }
        }
    }

    Node* getNext(Node* cur, int i) {
        Node* nxt = cur->next[i];
        if (!nxt) {
            while (cur && !cur->next[i])  cur = cur->fail;
            nxt = cur ? cur->next[i] : root;
        }
        return nxt;
    }

    bool dfs(Node* cur) {
        STATUS[cur] = ING;
        for (int i = 0; i < 2; ++i) {
            // get the next node in AC automation
            Node* nxt = getNext(cur, i);
            if (nxt->ok == false)  continue;  // if nxt is invalid
            if (STATUS[nxt] == ING)  return true;  // find a loop
            if (STATUS[nxt] == UN) {
                if (dfs(nxt))  return true;
            }
        }
        STATUS[cur] = ED;
        return false;
    }
};
int main() {
    scanf("%d", &n);
    AC tr;
    while (n-- > 0) {scanf("%s", p);  tr.insert(p); }
    tr.build();
    if (tr.dfs(tr.root))  printf("YES\n");
    else  printf("NO\n");
}