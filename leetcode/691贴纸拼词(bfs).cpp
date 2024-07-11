#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// https://leetcode.cn/problems/stickers-to-spell-word/solutions/1490623/tie-zhi-pin-ci-by-leetcode-solution-9g3z/

class Solution
{
public:
    // 处理字符串的典
    static string getNextString(string &target, string &sticker)
    {
        string result;
        vector<int> tar(26);
        vector<int> sti(26);

        for (auto &ch : target)
            tar[ch - 'a']++;

        for (auto &ch : sticker)
            sti[ch - 'a']++;

        for (int i = 0; i < 26; i++)
        {
            if (tar[i] > sti[i])
                result += string(tar[i] - sti[i], 'a' + i);
        }

        return result;
    }

    int minStickers(vector<string> &stickers, string target)
    {
        vector<vector<string>> graph(26);
        unordered_set<string> vis; // 放剩余的字符串，判断是否进过

        // 能处理x的放入
        for (auto &ch : stickers)
        {
            sort(ch.begin(), ch.end());
            for (int i = 0; i < ch.size(); i++)
            {
                if (i == 0 || ch[i] != ch[i - 1])
                    graph[ch[i] - 'a'].push_back(ch);
            }
        }

        sort(target.begin(), target.end());
        vis.insert(target);
        queue<string> q;
        q.push(target);
        int ans = 1;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string cur = q.front();
                q.pop();
                for (auto &s : graph[cur[0] - 'a'])
                {
                    string next = getNextString(cur, s);
                    if (next.empty())
                        return ans;
                    if (vis.find(next) == vis.end())
                    {
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
            ans++;
        }
        return -1;
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
