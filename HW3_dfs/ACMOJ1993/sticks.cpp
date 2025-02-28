#include <iostream>
#include <algorithm>
using std::cin;
int ans = 0, N, a[65], sum = 0, max = 0, tp[65], tpindex, m;
bool book[65] = {0};
bool cmp (int x, int y) {
    return x > y;
}
int find_next_index(void) {
    for (int i = 0; i < N; ++i) {
        if (!book[i])  return i;
    }
    return 100;
}
bool dfs (int l, int s) {
    for (int i = l; i < N; ++i) {
        if (!book[i]) {
            if (a[i] + tp[tpindex] > s)  continue;
            if (a[i] + tp[tpindex] == s) {
                tp[tpindex] = s;
                ++tpindex;
                book[i] = 1;
                return true;
            }
            if (a[i] + tp[tpindex] < s) {
                tp[tpindex] += a[i];
                book[i] = 1;
                if (dfs(0, s) == false) { book[i] = 0;  tp[tpindex] -= a[i];}
                else return true;
            }
        } else  continue;
    }
    return false; 
}
void it (int k) {
    bool check = 1;  tpindex = 0;
    for (int i = 0; i < N; ++i) { tp[i] = 0;  book[i] = 0; }
    if (k == 1) { ans = sum;  return; }
    while (sum % k > 0 || ((sum % k == 0) && sum / k < max))  k--;
    //suc = 0;  
    for (int i = 0; i < N; ++i) {
        while(book[i])  ++i;
        if (dfs(i, sum / k) == 0) { check = 0;  break; }
    }
    if (check==0)  it(--k);
    else {ans = sum / k;  return; }
}
int main () {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum += a[i];
        if (max < a[i])  max = a[i];
    }
    std::sort(a,a + N,cmp);
    it(N);
    std::cout << ans << std::endl;
    return 0;
}