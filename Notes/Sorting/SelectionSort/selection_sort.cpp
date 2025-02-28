#include <iostream>
using std::cin,std::cout,std::endl;
void SelecSort(int* a, int n);
int main(){
    int a[10000],num;
    int i = 0;
    while (cin >> num) {
        a[i] = num;
        ++i;
    }
    SelecSort(a, i);
    for (int k = 0; k < i; ++k)  cout << a[k] << " ";
    cout << endl;
    return 0;
}
void SelecSort(int* a, int k) {
    for (int i = 0; i < k; ++i) {
        //int ith = i;
        for (int j = i + 1; j < k; ++j) {
            //int jth = j;
            if (a[i] > a[j])  std::swap(a[i],a[j]);
        }
        // for (int p = 0; p < 5; ++p)  cout << a[p] << " ";
        // cout << endl;
    }
}
/*
思路：每次循环都保证第i个是第i小的
时间复杂度：O(n*n)
swap可以不重新设置i，j分别为ith，jth，因为swap只交换ai，aj这两个地址中的内容，而不改变地址，ai仍然指向原来的位置，只是内容变成了另外的数字
*/