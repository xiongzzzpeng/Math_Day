#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countKeyChanges(string s)
    {
        int ans = 0;
        for (int i = 1; i < s.size(); i++)
        {
            ans += (s[i - 1] & 31) != (s[i] & 31); // 大写字母跟小写字母二进制的后5位是一样的，&31就是取后五位
        }
        return ans;
    }
};