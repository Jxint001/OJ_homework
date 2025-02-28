#include <iostream>
using std::cin,std::cout,std::endl;
void Merge(int* abg, int* aend, int* bbg, int* bend, int* temp);
void Sort(int* a, int l, int r);
long long int ans = 0;
int a[500001];
int main() {
    int n;
    int i;
    cin >> n;
    for (i = 0; i < n; ++i)  cin >> a[i];
    Sort(a, 0, n);
    //for (i = 0; i < n; ++i)  cout << a[i] << " "; 
    //cout << endl;
    cout << ans << endl;
    return 0;
}
void Merge(int* abg, int* aend, int* bbg, int* bend, int* temp) {
    int* s = abg;
    while (abg < aend && bbg < bend) {
        if (*abg > *bbg) {
            *temp = *bbg;
            ++temp;  ++bbg;
            ans += aend - abg;
        }else {
            *temp = *abg;
            ++temp;  ++abg;
        }
    }
    for (; abg < aend; ++abg, ++temp)  *temp = *abg;
    for (; bbg < bend; ++bbg, ++temp)  *temp = *bbg;
}
int temp[500001];
void Sort(int* a, int l, int r) {
    if (r - l <= 1)  return;
    int mid = l + ((r-l) >> 1);
    Sort(a, l, mid);  Sort(a, mid, r);
    Merge(a+l, a+mid, a+mid, a+r, temp+l);
    for (int i = l; i < r; ++i)  a[i] = temp[i];
}