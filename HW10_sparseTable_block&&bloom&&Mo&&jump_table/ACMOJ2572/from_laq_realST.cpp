#include <bits/stdc++.h>
using namespace std;

class SparseTable {
   private:
    vector<vector<int>> minST, maxST;
    vector<int> log;
    int a, b, n;

   public:
    SparseTable(const vector<vector<int>>& matrix, int a, int b, int n) {
        this->a = a;
        this->b = b;
        this->n = n;
        minST.resize(a + 1, vector<int>(b + 1));
        maxST.resize(a + 1, vector<int>(b + 1));
        log.resize(max(a, b) + 1);

        for (int i = 1; i <= max(a, b); i++) {
            log[i] = log[i / 2] + 1;
        }

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                minST[i][j] = maxST[i][j] = matrix[i][j];
            }
        }

        for (int k = 1; k <= log[n]; ++k) {
            for (int i = 1; i + (1 << k) - 1 <= a; ++i) {
                for (int j = 1; j + (1 << k) - 1 <= b; ++j) {
                    minST[i][j] = min(
                        minST[i][j],
                        min(minST[i + (1 << (k - 1))][j],
                            min(minST[i + (1 << (k - 1))][j + (1 << (k - 1))],
                                minST[i][j + (1 << (k - 1))])));
                    maxST[i][j] = max(
                        maxST[i][j],
                        max(maxST[i + (1 << (k - 1))][j],
                            max(maxST[i + (1 << (k - 1))][j + (1 << (k - 1))],
                                maxST[i][j + (1 << (k - 1))])));
                }
            }
        }
    }
    int queryMin(int x1, int y1) {
        int k = log[n], x2 = x1 + n - 1, y2 = y1 + n - 1;
        return min(
            {minST[x1][y1],
             min(minST[x2 - (1 << k) + 1][y1], minST[x1][y2 - (1 << k) + 1]),
             min(minST[x2 - (1 << k) + 1][y2 - (1 << k) + 1],
                 minST[x1][y2 - (1 << k) + 1])});
    }
    int queryMax(int x1, int y1) {
        int k = log[n], x2 = x1 + n - 1, y2 = y1 + n - 1;
        return max(
            {maxST[x1][y1],
             max(maxST[x2 - (1 << k) + 1][y1], maxST[x1][y2 - (1 << k) + 1]),
             max(maxST[x2 - (1 << k) + 1][y2 - (1 << k) + 1],
                 maxST[x1][y2 - (1 << k) + 1])});
    }
};

int main() {
    int n, a, b;
    cin >> a >> b >> n;
    vector<vector<int>> matrix(a + 1, vector<int>(b + 1));
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    SparseTable st(matrix, a, b, n);
    int mindis = INT_MAX;
    for (int i = 1; i <= a - n + 1; i++) {
        for (int j = 1; j <= b - n + 1; j++) {
            int minval = st.queryMin(i, j);
            int maxval = st.queryMax(i, j);
            mindis = min(mindis, maxval - minval);
        }
    }
    cout << mindis << endl;
    return 0;
}
/*
对于 minST[i][j]，它的值是通过以下四个子区间的最小值来计算的：
minST[i][j]
minST[i + (1 << (k-1))][j]
minST[i][j + (1 << (k-1))]
minST[i + (1 << (k-1))][j + (1 << (k-1))]
*/