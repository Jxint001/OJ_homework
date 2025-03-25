#include <climits>
#include <map>
#include <iostream>
using namespace std;
long long exp(long long x, long long y) {
    long long z = x;
    for (long long i = 1; i < y; ++i) {
        x *= z;
    }
    return x;
}
int main() {
    for (long long i = 0; i < LONG_LONG_MAX; ++i) {
        map<long long, long long> cnt;
        long long x_1 = exp(i, 1) % 7;
        long long x_2 = exp(i, 2) % 7;
        long long x_3 = exp(i, 3) % 7;
        long long x_4 = exp(i, 4) % 7;
        long long x_5 = exp(i, 5) % 7;
        long long x_6 = exp(i, 6) % 7;
        cnt[x_1]++;cnt[x_2]++;cnt[x_3]++;cnt[x_4]++;cnt[x_5]++;cnt[x_6]++;
        if (cnt[x_1]==1 && cnt[x_2]==1 && cnt[x_3]==1 && cnt[x_4]==1 && cnt[x_5]==1 && cnt[x_6]==1) {
            cout << i << endl;  // this outputs 3
            cout << (x_1+x_2+x_3+x_4+x_5+x_6) % 7 << endl;
            break;
        }
    }
    return 0;
}