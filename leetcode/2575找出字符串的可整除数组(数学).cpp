#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://leetcode.cn/problems/find-the-divisibility-array-of-a-string/
class Solution
{
public:
    vector<int> divisibilityArray(string word, int m)
    {
        vector<int> ans(word.size());
        long long x = 0;
        for (int i = 0; i < word.size(); i++)
        {
            x = (x * 10 + (word[i] - '0')) % m;
            if (x == 0)
                ans[i] = 1;
            else
                ans[i] = 0;
        }
        return ans;
    }
};
