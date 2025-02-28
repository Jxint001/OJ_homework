#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
constexpr ll MOD = 1e9 + 7;
struct M {
    int num = 0;
    ll mtr[32][32];
    M() {
        for (int i = 0; i <= 31; ++i) {
            for (int j = 0; j <= 31; ++j)  mtr[i][j] = 0;
        }
    }
    ll value();
    ll rank = -1;
};
vector<M> MS(1005);
int n, m;
ll moddiv(ll x) {
    if (x == 1)  return 1;
    ll exp = MOD - 2, rst = 1;
    ll base = x;
    while (exp > 0) {
        if (exp % 2) {
            rst = (rst * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return rst;
}
ll M::value() {
    if (this->rank != -1)  return this->rank;
    int c, r = 1, i, j, k;
        for (c = 1; c <= m; ++c) {
            for (i = r, j = r + 1; j <= m; ++j) {
                if (abs(this->mtr[j][c]) > abs(this->mtr[i][c])) { i = j; }
            }
            if (this->mtr[i][c] == 0)  continue;
            if (i != r) {
                for (j = 1; j <= m; ++j) {
                    swap(this->mtr[i][j], this->mtr[r][j]);
                }
            }
            ll t = moddiv(this->mtr[r][c]);
            for (j = c; j <= m; ++j) {
                this->mtr[r][j] = (this->mtr[r][j] * t) % MOD;
            }
            for (int x = r + 1; x <= m; ++x) {
                t = this->mtr[x][c];
                for (j = c; j <= m; ++j) {
                    this->mtr[x][j] = (this->mtr[x][j] - t * this->mtr[r][j]) % MOD;
                    if (this->mtr[x][j] < 0) {
                        this->mtr[x][j] += MOD;
                    }
                }
            }
            ++r;
        }
        this->rank = r - 1;
        return r - 1;
}
int main() {
    // freopen("1.in","r",stdin);
    // freopen("1.ans","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        MS[i].num = i;
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= m; ++k) {
                cin >> MS[i].mtr[j][k];
            }
        }
    }
    auto last = unique(MS.begin() + 1, MS.begin() + n + 1, [](M& a, M& b) {
        return a.value() == b.value();
    });
    MS.erase(last, MS.end());
    cout << MS.size() - 1<< endl;
    for (int i = 1; i < MS.size(); ++i) {
        cout << MS[i].num << " ";
    }
    cout << endl;
    return 0;
}
