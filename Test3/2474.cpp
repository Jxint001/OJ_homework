#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long n, a[100005], cntm = 0, cnt0 = 0;
    long long t = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            ++cntm;
        }
        int tp = abs(a[i]);
        if (tp == 0) {
            t += 1;
            ++cnt0;
        } else {
            t += (tp - 1);
        }
    }
    if (cntm % 2 == 1) {
        if (cnt0 == 0) {
            t += 2;
        }
    }
    cout << t << endl;
    return 0;
}