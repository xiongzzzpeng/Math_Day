#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int magicTower(vector<int> &nums)
    {
        if (accumulate(nums.begin(), nums.end(), 0ll) < 0) // 见笔记19条
            return -1;
        int ans = 0;
        long long hp = 1;
        priority_queue<int> h; // 见笔记20条
        for (int n : nums)
        {
            if (n < 0)
                h.push(-n);
            hp += n;
            if (hp < 1)
            {
                hp += h.top();
                h.pop();
                ans++;
            }
        }
        return ans;
    }
};