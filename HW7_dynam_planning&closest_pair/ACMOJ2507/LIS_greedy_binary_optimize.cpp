#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 5, 0), tail, prex(n + 5, -1), index(n + 5, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(tail.begin(), tail.end(), a[i]);
        int idx = it - tail.begin();
        if (it == tail.end()) {
            tail.push_back(a[i]);
        } else {
            *it = a[i];
        }
        if (idx > 0) {
            prex[i] = index[idx - 1];
        }
        index[idx] = i;
    }
    int lis[n + 1], cnt = 0;
    int idx = index[tail.size() - 1];
    while (idx != -1) {
        lis[cnt++] = idx + 1;
        idx = prex[idx];
    }
    cout << tail.size() << endl;
    for (int i = cnt - 1; i >= 0; --i) {
        cout << lis[i] << " ";
    }
    cout << endl;
    return 0;
}