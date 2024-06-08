#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/minimum-size-subarray-sum/
// �򵥻�������ģ��

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = INT_MAX;
        // ��������ģ��
        for (int l = 0, r = 0, sum = 0; r < nums.size(); r++)
        {
            sum += nums[r];
            while (sum - nums[l] >= target)
                sum -= nums[l++]; // l�Ӵ��ڳ�ȥ������һֱ��ȥ��l�����ƶ�
            if (sum >= target)
                ans = min(ans, r - l + 1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
