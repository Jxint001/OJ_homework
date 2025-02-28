#include <iostream>
typedef  long long int ll ;
constexpr ll Max = 5e4 + 10;
using std::cin, std::cout ,std::endl;
ll n, k, nxt[Max], transition[Max][31];
int main() {
    cin >> n >> k;
    for (ll i = 1; i <= n; ++i) {
        cin >> nxt[i];
    }
    for (int i = 1; i <= n; ++i) transition[i][0] = nxt[i];
    for (int i = 1; (1ll << i) <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            transition[j][i] = transition[transition[j][i - 1]][i - 1];
        }
    }
    for (ll i = 1; i <= n; ++i) {
        int cp = i;
        for (ll j = 0; (1ll << j) <= k; ++j) {
            if (k & (1ll << j)) {
                cp = transition[cp][j];
            }
        }
        cout << cp << ' ';
    }
    cout << endl;
    return 0;
}