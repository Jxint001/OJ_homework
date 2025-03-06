#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int MOD = 10000007;

inline int read() {
    int c = getchar(), x = 0;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x;
}
class SegmentTree {
private:
    vector<ll> tree;
    int n;

public:
    SegmentTree(int size) {
        n = 1;
        while (n < size) {
            n <<= 1;
        }
        tree.resize(2 * n, 0LL);  // 建成2的幂次大小好算叶子节点
    }
    void update(int pos, int val) {
        pos += n; // 转换为叶子节点的位置
        tree[pos] += val;
        for (pos >>= 1; pos >= 1; pos >>= 1) {  // 从下到上O(logn)
            tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
        }
    }
    ll query(int l, int r) {
        l += n;
        r += n;
        ll ans = 0;
        while (l <= r) {
            if (l % 2 == 1) {
                ans += tree[l];
                l++;
            }
            if (r % 2 == 0) {
                ans += tree[r];
                r--;
            }
            // 向上一层
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
};
int main() {
    int n = read();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = read();
    }

    vector<int> newa(a);  // 排序去重，实力要求严格递增，相同实力不同编号的队员共享rank
    sort(newa.begin(), newa.end());
    auto last = unique(newa.begin(), newa.end());
    newa.erase(last, newa.end());
    int m = newa.size();

    // 对于每个a[j]，计算左边所有比它小的元素总和
    vector<ll> left_sum(n, 0);
    SegmentTree st_left(m);
    for (int j = 0; j < n; ++j) {
        int rank = lower_bound(newa.begin(), newa.end(), a[j]) - newa.begin();  // a[j]在newa的下标
        if (rank > 0) {  // 存在比a[j]小的元素
            left_sum[j] = st_left.query(0, rank - 1);  // 优化查询[0, rank-1]的和
        } else {
            left_sum[j] = 0;
        }
        st_left.update(rank, a[j]);  // 更新线段树rank位置的值，以便后续查询
    }

    // 对于每个a[j]，计算右边所有比它大的元素总和
    vector<ll> right_sum(n, 0);
    SegmentTree st_right(m);
    for (int j = n - 1; j >= 0; --j) {
        int upper_rank = upper_bound(newa.begin(), newa.end(), a[j]) - newa.begin();
        if (upper_rank < m) {
            right_sum[j] = st_right.query(upper_rank, m - 1);
        } else {
            right_sum[j] = 0;
        }
        int rank = lower_bound(newa.begin(), newa.end(), a[j]) - newa.begin();
        st_right.update(rank, a[j]);
    }

    ll ans = 0;
    for (int j = 0; j < n; ++j) {
        ll product = ( (a[j] % MOD) * (left_sum[j] % MOD) % MOD ) * (right_sum[j] % MOD) % MOD;
        ans = (ans + product) % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}