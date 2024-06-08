#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/count-the-number-of-special-characters-i/description/
// https://leetcode.cn/circle/discuss/CaOJ45/   �������
// ��д��ĸ��ASCII��Сд�ĵ���λ��һ��������һ��
// ASCII >> 5 & 1 �жϴ���С��0�Ǵ�1��С  ASCII & 31 ȡ����λ�����ǵڼ�λ��

class Solution
{
public:
    int numberOfSpecialChars(std::string word)
    {
        int mask[2] = {0, 0};

        for (char c : word)
        {
            int index = (c >> 5) & 1;
            mask[index] |= (1 << (c & 31)); // ���Ԫ�ص�λ����
        }

        return __builtin_popcount(mask[0] & mask[1]);
    }
};

// ���Ͻⷨ
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
