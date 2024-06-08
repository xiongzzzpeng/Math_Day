#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/count-the-number-of-special-characters-i/description/
// https://leetcode.cn/circle/discuss/CaOJ45/   相关文章
// 大写字母的ASCII跟小写的第五位不一样，其他一样
// ASCII >> 5 & 1 判断大还是小，0是大，1是小  ASCII & 31 取后五位，就是第几位数

class Solution
{
public:
    int numberOfSpecialChars(std::string word)
    {
        int mask[2] = {0, 0};

        for (char c : word)
        {
            int index = (c >> 5) & 1;
            mask[index] |= (1 << (c & 31)); // 添加元素的位运算
        }

        return __builtin_popcount(mask[0] & mask[1]);
    }
};

// 集合解法
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        unordered_set<char> lower, upper;
        for (auto ch : word)
        {
            if (islower(ch))
                lower.insert(ch);
            else
                upper.insert(tolower(ch));
        }
        int res = 0;
        for (auto c : lower)
            if (upper.find(c) != upper.end())
                res++;
        return res;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
