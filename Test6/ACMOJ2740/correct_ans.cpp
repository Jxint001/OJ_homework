#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int q, T, m;
string n;
vector<int> S;

ll dp[20][2];  // dp[pos][tight]:= 0 ~ pos-1位已经处理好，tight==1 则前面位数都匹配，反之 tight==0, 的方案数
inline void reset1() {
    for (int i = 0; i < 20; ++i)  dp[i][0] = dp[i][1] = 0;
}
ll solve1() {  // 数位dp
    ll ans = 0;
    int wei = n.length();
    for (ll cur = m, i = wei - 1; i > 0; cur *= m, --i) {ans += cur; }
    // 处理相同位数的吉利数个数，即dp[0][1]
    dp[wei][0] = dp[wei][1] = 1;
    for (int pos = wei - 1; pos >= 0; --pos) {
        for (int tight = 0; tight <= 1; ++tight) {
            ll cnt = 0;
            for (int d : S) {
                if (tight == 1 && d > n[pos] - '0')  continue;
                cnt += dp[pos + 1][tight == 1 && d == n[pos] - '0'];
            }
            dp[pos][tight] = cnt;
        }
    }
    ans += dp[0][1];
    return ans;
}


inline bool find(int x) {
    int l = 0, r = S.size() - 1;
    if (!r)  return S[0] == x;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (x == S[mid])  return true;
        else if (x < S[mid])  r = mid - 1;
        else l = mid + 1;
    }
    return false;
}

string solve2() {
    int wei = n.length();
    string ans(wei, '?');
    bool fillmax = false;
    for (int pos = 0; pos < wei; ++pos) {
        int cur = n[pos] - '0';
    
        if (fillmax) {
            ans[pos] = '0' + S.back();  continue;
        }
        if (find(cur)) {
            ans[pos] = n[pos];  continue;
        }
        // 没找到一样的，那就找最大的
        auto it = lower_bound(S.begin(), S.end(), cur);
        if (it != S.begin()) {
            --it;
            ans[pos] = '0' + *it;
            fillmax = true;
            continue;
        }
        // S 中数字都比cur大，只能把前位调小
        int j = pos - 1;
        while (j >= 0) {
            int prev = ans[j] - '0';
            // 在 S 中找一个比 prev 小的最大值
            auto it2 = lower_bound(S.begin(), S.end(), prev);
            if (it2 != S.begin()) {
                --it2;
                ans[j] = char('0' + *it2);
                pos = j;
                fillmax = true;
                break;
            }
            // 否则，再往前一位继续回退
            --j;
        }
        if (j < 0) {
            return string(wei - 1, '0' + S.back());
        }
    }

    // 去掉开始的0
    int start = 0;
    for (int i = 0; i < wei - 1; ++i) {
        if (ans[i] == '0')  ++start;
    }
    return ans.substr(start, wei - start);
}

int main() {
    cin >> q >> T;
    for(; T > 0; --T) {
        S.clear();
        cin >> m >> n;
        if (q == 1) {
            reset1();
            for (int i = 0, s; i < m; ++i) {
                cin >> s;  S.push_back(s);
            }
            cout << solve1() << endl;
        }
        if (q == 2) {
            S.clear();
            for (int i = 0, s; i < m; ++i) {
                cin >> s;  S.push_back(s);
            }
            std::sort(S.begin(), S.end());
            cout << solve2() << endl;
        }
    }
    return 0;
}