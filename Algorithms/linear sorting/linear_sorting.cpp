#include <climits>
#include <iostream>
using namespace std;
int main() {
    int n;  cin >> n;
    int x[n+5], out[n+5], mini = INT_MAX, maxi = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        mini = min(mini, x[i]);
        maxi = max(maxi, x[i]);
    }

    int cnt[maxi-mini+5];
    for (int i = 0; i <= maxi-mini; ++i)  cnt[i] = 0;
    for (int i = 1; i <= n; ++i)  ++cnt[x[i] - mini];
    for (int i = 1; i <= maxi-mini; ++i)  cnt[i] += cnt[i-1];
    for (int i = 1; i <= n; ++i)  out[cnt[x[i]-mini]--] = x[i];

    for (int i = 1; i <= n; ++i)  cout << out[i] << " ";
    cout << endl;
    return 0;
}