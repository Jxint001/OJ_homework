#include <iostream>
using std::cin,std::cout,std::endl;
void InsSort(int* a, int n);
int main(){
    int a[10000],num;
    int n = 0;
    while (cin >> num) {
        a[n] = num;
        ++n;
    }
    InsSort(a, n);
    for (int i = 0; i < n; ++i)  cout << a[i] << " ";
    cout << endl;
    return 0;
}
void InsSort(int* a, int n) {
    for (int i = 1; i < n; ++i) {
        int temp = a[i];
        if (a[i] < a[i-1]) {
            int j = i - 1;
            while (temp < a[j] && j >= 0) {
                a[j+1] = a[j];
                --j;
            }
            a[j+1] = temp;
        }
    }
}
/*
思路：把数字分为已排序和未排序两部分，每次从未排序的部分中选择一个插入到已排序的部分里正确的位置（就像打牌时抓取新牌插入旧牌中）
时间复杂度：最好时数组基本是有序的只需要遍历一次，O(n)
           最坏时数组颠倒，每次插入都需要遍历一遍已经排好序的部分(1+2+3+...+n) O(n*n)
*/