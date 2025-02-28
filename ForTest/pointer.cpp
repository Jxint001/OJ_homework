#include <iostream>
using std::cout, std::endl;
int returnmax(int a, int b) {
    if (a < b)  return b;
    else  return a;
}
void printmax(int (*p)(int , int )) {
    cout << p(1, 10) << endl;
}
int main() {
    // int* p;
    // int a = 10;
    // int** q;
    // int*** r;
    // p = &a;
    // q = &p;
    // r = &q;
    // cout << "this is p : " << p << endl;
    // cout << "this is *p : " << *p << endl;
    // cout << "this is q : " << q << endl;
    // cout << "this is *q : " << *q << endl;
    // cout << "this is r : " << r << endl;
    // cout << "this is *r : " << *r << endl;
    // cout << "this is **r : " << **r << endl;
    // cout << "this is ***r : " << ***r << endl;
    
    // cout << "pointers in array" << endl;
    // cout << "integer arry" << endl;
    // int A[] = {9, 43534, 4253325, 44, 1, 4392, 68745};
    // cout << "A : " << A <<" *A : " << *A << endl;
    // cout << "A + 1" << A + 1 << " *(A+1) : " << *(A + 1) << endl;
    // int B[2][3];
    // int t = 1;
    // for (int i = 0; i < 2; ++i) {
    //     for (int j = 0; j < 3; ++j) {
    //         B[i][j] = t;
    //         ++t;
    //     }
    // }
    // int (*p)[3] = B;
    // cout << "B address " << p << endl;
    // cout << "B address " << *p << endl;
    // cout << "B[1] address " << p + 1 << endl;
    // cout << "B[1] address " << *(p + 1) << endl;
    // cout << "B[1][1] : " << **(p + 1) << endl;
    // cout << "B[1][2] : " << *(*(p + 1) + 2) << endl;

    // int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // cout << *A << endl;
    // int (*p)(int, int) = &returnmax;
    // printmax(p);

    int&& r = 9;
    cout << r << endl;
    int*ptr = &r;
    cout << &r << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
    
    r = 10;
    cout << r << endl;
    cout << &r << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
    return 0;
}