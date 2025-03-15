#include <iostream>
using namespace std;
struct pnode{
    int v = 0, i = 0;  // value and index
};
void Merge(int s1, int e1, int s2, int e2, pnode* c, int* temp, int* index) {
    while (s1 < e1 && s2 < e2) {
        if (c[s1].v > c[s2].v) {
            *temp = c[s2].v;
            *index = c[s2].i;
            ++s2;
        } else {
            *temp = c[s1].v;
            *index = c[s1].i;
            ++s1;
        }
        ++temp;  ++index;
    }
    for (; s1 < e1; ++s1, ++temp, ++index) {*temp = c[s1].v;  *index = c[s1].i; }
    for (; s2 < e2; ++s2, ++temp, ++index) {*temp = c[s2].v;  *index = c[s2].i; }
}
void MergeSort(int l, int r, pnode* a) {
    if (r - l <= 1) {return; }
    int mid = (l+r) >> 1;
    MergeSort(l, mid, a);  MergeSort(mid, r, a);
    int temp[r-l+5], index[r-l+5];
    Merge(l, mid, mid, r, a, temp, index);
    for (int i = l; i < r; ++i) {a[i].v = temp[i-l];  a[i].i = index[i-l]; }
}
int main() {
    int n;  cin >> n;  // length of a
    pnode a[n+5];
    for (int i = 1; i <= n; ++i) {cin >> a[i].v;  a[i].i = i; }
    MergeSort(1, n + 1, a);
    // cout << endl;
    // for (int i = 1; i <= n; ++i) {cout << a[i].v << " "; }
    // cout << endl;
    for (int i = 1; i <= n; ++i) {cout << a[i].i << " "; }
    cout << endl;
    return 0;
}