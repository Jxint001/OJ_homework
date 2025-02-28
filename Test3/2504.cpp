#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    std::cin >> n;
    bool first = 1, de = 1;
    int l = 1, r = n;
    int lastl = 1, lastr = n, semax, now = -1;
    if (n == 1) {
        cout << "1 " << 1 << endl;
        return 0;
    }
    int l2l, l2r;
    while (l <= r) {
        cout << "0 " << l << " " << r << endl;
        if (first) {
            cin >> semax;
            now = semax;
            first = 0;
        } else {
            cin >> now;
        }
        if (r - l == 1) {
            if (now < r) {
                cout << "1 " << r << endl;
            } else {
                cout << "1 " << l << endl;
            }
            return 0;
        }
        int mid = lastl + (lastr - lastl) / 2;
        if (now != semax) {
            if (abs(l - lastl) == 1) {
                cout << "1 " << lastl << endl;
                return 0;
            }
            if (abs(lastr - r) == 1) {
                cout << "1 " << lastr << endl;
                return 0;
            }
            de = 1 - de;
            if (de) {
                l = l2l + 1;
                r = l2r;
            } else {
                l = l2l;
                r = l2r - 1;
            }
            //de = 1 - de;
        } else {
            if (de) {
                l = mid;
            } else {
                r = mid;
            }
        }
        l2l = lastl;  l2r = lastr;
        lastl = l;  lastr = r;
    }
}