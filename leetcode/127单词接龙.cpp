#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// ˫�����ģ��(����)
// https://leetcode.cn/problems/word-ladder/submissions/545983316/

class Solution
{
public:
    int ladderLength(string begin, string end, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(end) == dict.end())
            return 0;

        // ����С��һ��
        unordered_set<string> small;
        // ���һ��
        unordered_set<string> big;
        // ��С����չ����һ��
        unordered_set<string> next;

        small.insert(begin);
        big.insert(end);

        for (int len = 2; !small.empty(); len++) // ��ʼ����2��
        {
            for (auto &w : small)
            {
                string s = w;
                for (int j = 0; j < s.size(); j++)
                {
                    char old = s[j];
                    for (char change = 'a'; change <= 'z'; change++)
                    {
                        if (change != old)
                        {
                            s[j] = change;
                            if (big.find(s) != big.end())
                                return len;
                            if (dict.find(s) != dict.end())
                            {
                                dict.erase(s);
                                next.insert(s);
                            }
                        }
                    }
                    s[j] = old;
                }
            }

            // ˭С˭����һ����small��˭��˭big
            if (next.size() <= big.size())
            {
                small.swap(next);
            }
            else
            {
                small.swap(big);
                big.swap(next);
            }
            next.clear();
        }
        return 0;
    }
};

void issue()
{
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
