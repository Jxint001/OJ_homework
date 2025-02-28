#include <iostream>
typedef long long int LL;
using std::cin,std::cout;
LL FindLFBit (LL n);
LL CountBit (LL k);
int main() {
    LL n, ans = 0;
    cin >> n;
    LL np = n;
    LL i = 0;
    while (n ^ LL(0)) {
        LL k = FindLFBit(n);
        LL w = CountBit(k);
        ans += (w * (1LL << (w-1)) + 1LL) + i * (1LL << w);
        n -= k;
        i += 1;
        
    }
    cout << ans << '\n';
    return 0;
}
LL FindLFBit (LL n) {
    LL x = n;
    x |= x >> 1LL;
    x |= x >> 2LL;
    x |= x >> 4LL;
    x |= x >> 8LL;
    x |= x >> 16LL;
    x |= x >> 20LL;
    return x^(x >> 1LL);
}
LL CountBit (LL k) {
    LL w = 0;
    while (true) {
        if(k & (1LL << w)) break;
        ++w;
    }
    return w;
}
/*
思路：
按二进制位从高到低取1，分别加上对应1总数
*/