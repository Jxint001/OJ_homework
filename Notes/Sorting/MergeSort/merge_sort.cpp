#include <iostream>
using std::cin,std::cout,std::endl;
void MergeSort(int*, int, int);
void Merge(int*, int*, int*, int*, int*);
int a[10000];
int main(){
    int num, n = 0;
    while (cin >> num) {
        a[n] = num;
        ++n;
    }
    MergeSort(a, 0, n);
    for (int i = 0; i < n; ++i)  cout << a[i] << " ";
    cout << endl;
    return 0;
}
void MergeSort(int* a, int l, int r) {
    //划分
    if (r - l <= 1)  return;
    int mid = l + ((r - l) >> 1);
    //为了时间复杂度，不如不循环判断是否单增，log2更快
    // bool flag = 1;   //是单增
    // for (int i = l; i < r - 1; ++i) {
    //     if (a[i] > a[i+1]) {
    //         flag = 0;    //不单增，继续分
    //         break;
    //     }
    // }
    
    MergeSort(a, l, mid);  MergeSort(a, mid, r);

    //合并
    int temp[10000];
    Merge(a+l,a+mid,a+mid,a+r,temp+l);
    for (int i = l; i < r; ++i) a[i] = temp[i];
}
void Merge(int* abgn, int* aend, int* bbgn, int* bend, int* c) {
    while (abgn < aend && bbgn < bend) {
        if (*abgn > *bbgn) {
            *c = *bbgn;
            ++bbgn;
        }else {
            *c = *abgn;
            ++abgn;
        }
        ++c;
    }
    for (; abgn < aend; ++c, ++abgn) *c = *abgn;
    for (; bbgn < bend; ++c, ++bbgn) *c = *bbgn;
}
/*
思路：把数组分段排序后合并（分治），重点在合并：
        从左到右枚举a[i],b[j]（a前b后，二者均已有序），若a[i]<=（或者>=,看情况)b[j],则向数组c中插入a[i]，反之同理
        直到其中某个数组为空，把另一个数组剩余数字全都插入c中（共需要三个数组,可用vector）
     实际上不止两个数组，而是不停地分下去，最后也有可能一个分段里只有一个数字（为复杂度考虑，分段点尽量靠在中间）
时间复杂度：
空间复杂度：O(n)
*/