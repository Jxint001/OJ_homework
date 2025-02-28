#include <iostream>
#include <string.h>
using std::cin,std::cout,std::endl;
int cnt[1000],a[1000],b[1000];
void CountSort(int* a, int* b, int n, int max);
int main(){
    int num,max = 0; 
    int n = 0;
    while (cin >> num) {
        a[n] = num;
        if (max < num)  max = num;
        ++n;
    }
    CountSort(a, b, n, max);
    for (int i = 0; i < n; ++i)  cout << b[i] << " ";
    cout << endl;
    return 0;
}
void CountSort(int* a, int* b, int n, int max) {
    memset(cnt,0,sizeof(cnt));
    for (int i = 0; i < n; ++i)  ++cnt[a[i]];
    for (int i = 1; i <= max; ++i)  cnt[i] += cnt[i-1];
    for (int i = n-1; i >= 0; --i)  b[--cnt[a[i]]] = a[i];
}
/*
思路：先记录数组中每个数字出现的次数到计数数组，再计算后者的前缀和，此时利用前缀和逆序输出，相同数字出现的顺序不变（稳定）
通过改变前缀和的计算方式决定升序/降序
时间复杂度：O(n+w),w为待排序数组的数值范围
*/