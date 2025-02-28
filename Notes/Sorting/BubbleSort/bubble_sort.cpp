#include <iostream>
using std::cin,std::cout,std::endl;
void BubSort(int* a, int n);
int main(){
    int a[10000],num;
    int n = 0;
    while (cin >> num) {
        a[n] = num;
        ++n;
    }
    BubSort(a, n);
    for (int i = 0; i < n; ++i)  cout << a[i] << " ";
    cout << endl;
    return 0;
}
void BubSort(int* a, int n) {
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < n-1; ++i) {
            if (a[i] > a[i+1]) {
                std::swap(a[i], a[i+1]);
                flag = true;
            }
        }
    }
}
/*
思路：每次比较相邻两项大小，直到所有的相邻两项都不需要交换
时间复杂度：最好只需要遍历一次，O(n-1)
           最坏需要C(2,n)次，O(n*n)
*/