#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/sum-of-digit-differences-of-all-pairs/description/
// ת��Ϊ��ÿ��λ���ж��ٲ�һ��������
// ���λ��3 3 2��������
class Solution
{
public:
    long long sumDigitDifferences(vector<int> &nums)
    {
        long long ans = 0;
        vector<array<int, 10>> cnt(to_string(nums[0]).size()); // �﷨
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            for (int j = 0; x; x /= 10, j++)
            {
                int d = x % 10;
                // ��ǰi - cnt[i]���Ǵ����ж��ٲ�һ����
                ans += i - cnt[j][d]++; // j�Ǹ�λ����ʮλ...d��ֵ
            }
        }
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
    vector<int> nums = {13, 23, 12}; // ʾ���������飬���Ը�����Ҫ�޸�
    Solution solution;
    long long result = solution.sumDigitDifferences(nums);
    cout << result << endl;
    return 0;
}
