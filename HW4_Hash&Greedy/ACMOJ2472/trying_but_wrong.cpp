#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::cin, std::cout, std::endl, std::vector;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> b(n), a(m);

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    std::priority_queue<int, vector<int>, std::greater<int>> minHeap;

    int j = 0;
    long long money = 0;
    for (int i = 0; i < m; ++i) {
        while (j < n && b[j] < a[i]) {
            j++;
        }
        while (j < n && b[j] >= a[i]) {
            minHeap.push(b[j]);
            j++;
        }

        if (minHeap.empty()) {
            cout << -1 << endl;
            return 0;
        }
        money += minHeap.top();
        minHeap.pop();
    }

    cout << money << endl;
    return 0;
}