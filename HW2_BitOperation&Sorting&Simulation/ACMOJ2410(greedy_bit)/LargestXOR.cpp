#include <stdio.h>
typedef unsigned long long int ULL ;

ULL base[64];
void FindBase(ULL);
inline ULL read() {
    char ch = getchar();
	ULL x = 0, f = 1;
    while(ch > '9' || ch < '0')
	{
		if(ch == '-')  f = -1;
		ch = getchar();
	}
    while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    return x * f;
}
int main() {
    ULL n = read();
    ULL a;
    for (size_t i = 0; i < n; ++i) {
        FindBase(a = read());
    }
    ULL ans = 0;
    for (size_t i = 0; i < 64; ++i) {
        if((ans ^ base[63-i]) > ans)  ans ^= base[63-i];
    }
    printf("%llu\n",ans);
    return 0;
}  
//等价于如果a最后不能被异或成0，那就插入a为基
void FindBase(ULL a) {
    for (int i = 63; i >= 0; --i) {
        if(!(a >> ULL(i))) continue;   //从大到小第i位是0
        //从大到小第i位不是0
        if(!base[i]) {  //第i个基还空着
            base[i] = a;
            break;
        }
        //第i个基已经填过了,继续判断a能否被已经填入的基表示
        a ^= base[i];
    }
}
/*
先找到一组线性基（即加法为异或，乘法为与时的最大线性无关组），再用max求得最大异或和
线性基满足：随便异或，异或和不等于0
如何满足：让最高位的1位置不同就行了
筛选（贪心）：二进制只有两种情况，要这个基，不要这个基
*/