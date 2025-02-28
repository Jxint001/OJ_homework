#include <iostream>
#include <algorithm>
using std::cin, std::cout, std::endl;
int main() {
    int n, m;
    cin >> n >> m;
    int l[m + 3], p[m + 3], sum_left[m + 3];
    for (int i = 0; i <= m; ++i)  sum_left[i] = 0;
    int sum = 0;
    for (int i = 1; i <= m; ++i)  {cin >> l[i];  sum += l[i];}
    sum_left[1] = sum;
    for (int i = 2; i <= m; ++i)  {sum_left[i] = sum_left[i - 1] - l[i - 1];}
    if (sum < n) {
        cout << -1 << endl;
        return 0;
    } else if (sum == n) {
        int tp = 1;
        p[1] = 1;
        for(int i = 2; i <= m; ++i) {
            p[i] = tp + l[i - 1];
            tp += l[i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            cout << p[i] << " ";
        }
        cout << endl;
        return 0;
    } else {  //sum > n
        bool reach = false;
        int end = l[1];
        p[1] = 1;
        for (int i = 2; i <= m; ++i) {
            p[i] = std::max(n - sum_left[i] + 1, p[i - 1] + 1);
            end = p[i] + l[i] - 1;
            if (end > n) {
                cout << -1 << endl;
                return 0;
            }
        }
        if (end < n) {
            cout << -1 << endl;
            return 0;
        }
        for (int i = 1; i <= m; ++i) {
            cout << p[i] << " ";
        }
        cout << endl;
        return 0;
    }
    return 0;
}