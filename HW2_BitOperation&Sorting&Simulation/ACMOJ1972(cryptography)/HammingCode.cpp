#include <iostream>
using std::cin;
bool code[256];
bool count(int k,int bit) {
    bool x = 0;
    for(int i = 0;i < 256; ++i) {
        if(i & (1 << k)) {
            x ^= code[i];
        }
    }
    return x^code[bit];
}
int main() {
    for(int i = 0; i < 256; ++i) cin >> code[i];
    int bit = 1,ans = 0;
    for(int k = 0; k < 8; ++k) {
        if(count(k,bit) == code[bit]) {
            //左侧插入0
            ans = (0 << k) + ans;
        }else {
            //左侧插入1
            ans = (1 << k) + ans;
        }
        bit *= 2;
    }
    std::cout << ans << std::endl;
    return 0;
}
//如果某位不对，则错误的数字该位是1，否则为0