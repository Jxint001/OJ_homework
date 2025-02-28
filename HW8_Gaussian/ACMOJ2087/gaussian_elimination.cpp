#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
constexpr int MOD = 998244353;
int n, back;
ll a[303][304], ans[303], pvt[303];
ll moddiv(ll x) {
    if (x == 1)  return 1;
    ll exp = MOD - 2;
    long long result = 1, b = x;
    while (exp > 0) {
        if (exp % 2) {
            result = (result * b) % MOD;
        }
        b = (b * b) % MOD;
        exp /= 2;
    }
    if (result < 0)  result += MOD;
    return result;
}
int guass() {
    int c, r = 1, i, j, x;
    for (c = 1; c <= n; ++c) {  //columns
        for (i = r, j = r + 1; j <= n; ++j) {   //find max abs(c)
            if (abs(a[j][c]) > abs(a[i][c])) { i = j; }
        }
        if (a[i][c] == 0)  continue;
        if (i != r) {       //ensure pivot in top row has max value
            for (j = 1; j <= n + 1; ++j) { swap(a[i][j], a[r][j]); }
        }
        pvt[r] = c;     //c is the pivot of i_th row
        ll t = moddiv(a[r][c]);
        for (j = c; j <= n + 1; ++j) { a[r][j] = (a[r][j] * t) % MOD; }   //normalization
        for (x = r + 1; x <= n; ++x) {    //elimination
            t = a[x][c];
            for (j = c; j <= n + 1; ++j) { a[x][j] = (a[x][j] - t * a[r][j]) % MOD;  if (a[x][j] < 0) a[x][j] += MOD;}
        }
        ++r;
    }
    for (i = r; i <= n; ++i) {      //exceed maximum row
        if (a[i][n + 1] != 0) {return -1;}
    }
    return r - 1;   //back substitution from (r - 1)_th row
}
void solve(int c,int r) {
    if (!c) {
        for (int i = 1; i < n; ++i) {cout << ans[i] << " ";}
        cout << ans[n] << endl;
        return;
    }
    if (c == pvt[r]) {
        ans[c] = a[r][n + 1];
        for (int j = n; j > c; --j) { ans[c] = (ans[c] - ans[j] * a[r][j]) % MOD; if (ans[c] < 0)  ans[c] += MOD;}
        solve(c - 1, r - 1);
    } else {  //no need for this problem?
        ans[c] = 0;
        solve(c - 1, r);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n + 1; ++j) {
            cin >> a[i][j];
        }
    }
    back = guass();
    if (back == -1) {
        cout << "No Solution" << endl;
        return 0;
    } else if (back != n) {
        cout << "No Unique Solution" << endl;
        return 0;
    }
    solve(n, back);
    return 0;
}