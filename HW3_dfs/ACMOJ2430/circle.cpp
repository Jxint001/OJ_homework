#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
typedef  long long int ll ;
using std::cin, std::cout ,std::endl, std::unordered_map;

std::vector<std::vector<ll>> circle;
std::unordered_map<ll, ll> find_next_pos;
ll k, cnt = -1, n, tr[50005];
ll startcir;

void dfs() {
    ++cnt;
    if (cnt == k)  return;
    std::vector<ll>  tmp(n + 1);
    for (int i = 1; i <= n; ++i) {
        tmp[i] = find_next_pos.find(circle[cnt][i])->second;
    }

    bool same = false;
    
    ll index = 0;
    for (auto& i: circle) {
        if (i == tmp) { same = true;  startcir = index; break;}
        ++index;
    }
    if (same)  return;
    circle.push_back(tmp);
    dfs();
    return;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> tr[i];
        find_next_pos.insert(std::make_pair(i, tr[i]));
    }
    std::vector<ll>  tp(n + 1);
    for (int i = 1; i <= n; ++i)  tp[i] = i;
    circle.push_back(tp);
    dfs();
    ll remain;
    if (cnt == k) {
        for (int i = 1; i <= n; ++i) {
            cout << circle[cnt][i] << ' ';
        }
        cout << endl;
    } else {
        remain = startcir + ((k - startcir) % (cnt - startcir + 1));
        for (int i = 1; i <= n; ++i) {
            cout << circle[remain][i] << ' ';
        }
        cout << endl;
    }
    return 0;
}