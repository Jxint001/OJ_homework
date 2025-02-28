#include <iostream>
typedef long long ll;
using namespace std;
ll ans = 0;
void merge(ll* abg, ll* bbg, ll* aend, ll* bend, ll* c) {
    while (abg != aend && bbg != bend) {
        if (*abg >= *bbg) {
            *c = *bbg;
            bbg++;
        } else {
            *c = *abg;
            abg++;
            ans += (bend - bbg);
        }
        c++;
    }
    for (ll* it = abg; it != aend; it++, c++) { *c = *it; }
    for (ll* it = bbg; it != bend; it++, c++) { *c = *it; }
}
void msort(ll* a, ll l, ll r) {
    if (r - l <= 1) { return; }
    ll mid = l + (r - l) / 2;
    msort(a, l, mid);   msort(a, mid, r);
    ll* temp = new ll[r - l];
    merge(a + l, a + mid, a + mid, a + r, temp);
    for (ll i = l, cnt = 0; i < r; ++i, ++cnt) { a[i] = temp[cnt]; }
    delete[] temp;
}
int main() {
    ll N, a[200005];
    cin >> N;
    for (ll i = 1; i <= N; ++i) {
        static ll t;
        cin >> t;
        a[i] = t - i * i; 
    }
    // for (ll i = 1; i <= N; ++i) {   
    //     cout << a[i] << " ";
    // }
    //cout << endl;
    msort(a, 1, N + 1);
    // for (ll i = 1; i <= N; ++i) {   
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    cout << ans << endl;
    return 0;
}