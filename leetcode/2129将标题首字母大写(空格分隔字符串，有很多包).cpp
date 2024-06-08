#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    string capitalizeTitle(string title)
    {
        istringstream ss(title); // 按空格分割字符
        string ans, s;
        while (ss >> s)
        {
            if (!ans.empty())
                ans += ' ';
            if (s.size() > 2)
            {
                ans += toupper(s[0]); // 将首字母变成大写
                s = s.substr(1);      // 复制子串
            }
            for (char c : s)
            {
                ans += tolower(c); // 剩余的字母变小写
            }
        }
        return ans;
    }
};