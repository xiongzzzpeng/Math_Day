#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/find-the-width-of-columns-of-a-grid/description/

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> grid{{-15, 1, 3}, {15, 7, 12}, {5, 6, -2}};
    int n = grid[0].size();
    vector<int> ans(n);
    // �����еķ�ʽ
    for (int i = 0; i < n; i++)
    {
        for (auto row : grid)                                    // ����i == 0���������ǵ�һ�еĵ�0�����ڶ��еĵ�0��...
            ans[i] = max(ans[i], (int)to_string(row[i]).size()); // �󳤶ȷ���
    }
    return 0;
}
