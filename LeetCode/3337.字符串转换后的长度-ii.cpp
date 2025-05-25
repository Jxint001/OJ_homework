#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=3337 lang=cpp
 *
 * [3337] 字符串转换后的长度 II
 */

// @lc code=start    
static const int SIZE = 26;
static const int MOD = 1e9 + 7;

struct Matrix{
    long long m, n;
    long long A[SIZE][SIZE];
    
    Matrix(long long _m, long long _n): m(_m), n(_n) {}
    void init() {
        memset(A, 0, sizeof A);
    }
    Matrix operator* (const Matrix B)  const {
        Matrix C(m, B.n);
        C.init();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < B.n; ++j) {
                for (int k = 0; k < n; ++k) {
                    C.A[i][j] = (C.A[i][j] + A[i][k] * B.A[k][j] % MOD) % MOD;
                }
            }
        }
        return C;
    }
};
class Solution {
public:
    Matrix pow(Matrix A, int q) {
        Matrix C(A.m, A.n);
        C.init();
        for (int i = 0; i < C.m; ++i)  C.A[i][i] = 1;
        while (q) {
            if (q & 1)  C = C * A;
            A = A * A;
            q >>= 1;
        }
        return C;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Matrix m(SIZE, SIZE);  m.init();
        for (int i = 0; i < SIZE; i++) {
            for (int j = i + 1; j <= i + nums[i]; j++) {
                m.A[i][j % SIZE] = 1;
            }
        }
        Matrix mt = pow(m, t);

        int cnt[SIZE]{};
        for (char c : s) {
            cnt[c - 'a']++;
        }

        long long ans = 0;
        for (int i = 0; i < SIZE; i++) {
            // m 第 i 行的和就是 f[t][i]
            long long sum = 0;
            for (int j = 0; j < SIZE; ++j) {
                sum += mt.A[i][j];
            }
            ans += sum * cnt[i];
        }
        return ans % MOD;
    }
};
// @lc code=end

