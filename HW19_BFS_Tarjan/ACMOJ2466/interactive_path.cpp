#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

bool vis[maxn];
int cur = 0;
vector<int>a[maxn];

struct State{
    int cur, fa, adj;
}st[maxn << 1];

string ask (int x) {
    cout << x << endl;
    string ret;
    cin >> ret;
    if (ret == "FAIL") exit(0);
    return ret;
}

inline void answer (string ans) {
    cout << ans << endl;
    exit(0);
}


int main() {
    // 在0，想去n-1号点
    int n;
    string s;
    cin >> n >> s;
    
    if (s[n - 1] == '1') {
        s = ask(n);
        answer("yes");
    }
    for (int i = 0; i < n; ++i) 
        if (s[i] == '1') {a[0].push_back(i); }
    
    int top = 0;
    if (!a[0].size()) st[++top] = {0, -1, -1};
    else st[++top] = {0, -1, 0};
    vis[0] = true;

    while (top > 0) {
        auto& C = st[top];
        int u = C.cur, fa = C.fa, adj = C.adj;
        
        if (adj == -1 || adj >= a[u].size()) {  // 没有邻居或者所有邻居都走完了，可以回溯
            --top;
            if (fa != -1) {
                ask(fa + 1);  cur = fa;
                if (cur == n-1)  answer("yes");
            }
            continue;
        }

        int v = a[u][adj];
        ++C.adj;
        if (!vis[v]) {
            string lst = ask(v + 1);  // 移动到邻居v
            for (int i = 0; i < n; ++i) 
                if (lst[i] == '1') {a[v].push_back(i); }
            vis[v] = true;
            cur = v;

            if (cur == n-1)  answer("yes");

            if (!a[v].size()) {st[++top] = {v, u, -1}; }
            else {st[++top] = {v, u, 0}; }
        }
    }
    answer("no");
}