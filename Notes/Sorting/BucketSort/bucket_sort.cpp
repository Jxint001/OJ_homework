#include <iostream>
#include <vector>
using std::cin,std::cout,std::endl,std::vector;
void BuckSort(int* a, int n, int range, int max);
int main(){
    int a[10000], num, range, max = 0, min = 200000000;
    int n = 0;
    while (cin >> num) {
        if (num > max)  max = num;
        if (num < min)  min = num;
        a[n] = num;
        ++n;
    }
    range = max - min;
    BuckSort(a, n, range, max);
    for (int i = 0; i < n; ++i)  cout << a[i] << " ";
    cout << endl;
    return 0;
}
void BuckSort(int* a, int n, int range, int max) {
    int size = range / n + 1;
    vector<int> bucket[10000];
    //初始化
    for (int i = 0; i < n; ++i)  bucket[i].clear();
    //放入桶
    for (int i = 0; i < n; ++i) {
        bucket[a[i] / size].push_back(a[i]);
    }
    
    int p = 0;
    for (int i = 0; i < n; ++i) {
        if (i < max / size + 1) {
            //桶内插入排序
            for (int k = 1; k < bucket[i].size(); ++k) {
                if (bucket[i][k] < bucket[i][k - 1]) {
                    int key = bucket[i][k];
                    int tp = k - 1;
                    while (key < bucket[i][tp] && tp >= 0) {
                        bucket[i][tp + 1] = bucket[i][tp];
                        --tp;
                    }
                    bucket[i][tp + 1] = key;
                }
            }
        }
        //放回原数组
        for (int j = 0; j < bucket[i].size(); ++j) {
            a[p++] = bucket[i][j];
        }
    }
}
/*
适用于值域大但比较均匀的输入数据
思路：把数据分到不同的桶里，非空桶内排序，放回原来的序列
时间复杂度：最好：O(n)
           最坏：O(n*n)
*/  