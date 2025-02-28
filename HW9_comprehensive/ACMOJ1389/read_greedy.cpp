#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main() {
    int N, M, w[505], d[1005];
    bool visit[505];
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) {
        cin >> w[i];
        visit[i] = 0;
    }
    list<int> ord;
    for (int i = 1; i <= M; ++i) {
        cin >> d[i];
        if (!visit[d[i]]) {
            visit[d[i]] = 1;
            ord.push_back(d[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= M; ++i) {
        auto it = find(ord.begin(), ord.end(), d[i]);
        for (auto iter = ord.begin(); iter != it; ++iter) {
            ans += w[*iter];
        }
        ord.erase(it);
        ord.insert(ord.begin(), d[i]);
    }
    cout << ans << endl;
    return 0;
}