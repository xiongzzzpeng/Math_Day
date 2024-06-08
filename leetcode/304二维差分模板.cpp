#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/range-sum-query-2d-immutable/
class NumMatrix
{
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        sum = vector<vector<int>>(n + 1, vector<int>(m + 1, 0)); // 加0，好计算
        for (int a = 1, c = 0; c < n; a++, c++)
            for (int b = 1, d = 0; d < m; b++, d++)
                sum[a][b] = matrix[c][d]; // 拷贝值
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1]; // 从1开始，二维差分公式：自己+左+上-左上
    }

    int sumRegion(int a, int b, int c, int d)
    {
        c++;
        d++;
        return sum[c][d] - sum[c][b] - sum[a][d] + sum[a][b]; // 前缀和：c列：b行 - d行-a列d行+ab
    }
};
