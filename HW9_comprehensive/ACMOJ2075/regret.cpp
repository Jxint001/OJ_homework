#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ll p0, p1, p2, n, cnt = 2;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << n << endl;
        return 0;
    }
    cin >> p0 >> p1;
    for (ll i = 3; i <= n; ++i) {
        cin >> p2;
        if ((p1 - p0) * (p2 - p1) < 0) {
            p0 = p1;  p1 = p2;  ++cnt;
        } else {
            p1 = p2;
        }
    }
    cout << cnt << endl;
    return 0;
}