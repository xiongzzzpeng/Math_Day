#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<>()); // sortһ���Ǵ�С���󣬼���greater<>,���ɴӴ�С
        int def = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                def++;
                if (def == 3)
                    return nums[i];
            }
        }
        return nums[0];
    }
};