#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

class Solution
{
public:
    string alienOrder(vector<string> &words)
    {
        vector<vector<int>> graph(26);
        vector<int> indegree(26, -1);
        for (auto &s : words)
        {
            for (int i = 0; i < s.size(); i++)
            {
                indegree[s[i] - 'a'] = 0; // �õ��ľ���0��-1����û�õ�
            }
        }

        for (int i = 0, j, len; i < words.size() - 1; i++)
        {
            string cur = words[i];
            string next = words[i + 1];
            j = 0;
            len = min(cur.size(), next.size());

            for (; j < len; j++)
            {
                if (cur[j] != next[j]) // �ҵ�һ����һ��
                {
                    graph[cur[j] - 'a'].push_back(next[j] - 'a');
                    indegree[next[j] - 'a']++;
                    break;
                }
            }

            if (j < cur.size() && j == next.size()) // �����˵����Ϸ�
                return "";
        }

        // ��������
        queue<int> q;
        int kids = 0;
        for (int i = 0; i < 26; i++)
        {
            if (indegree[i] != -1)
                kids++;
            if (indegree[i] == 0)
                q.push(i);
        }

        string ans;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            ans.push_back(cur + 'a');

            for (auto next : graph[cur])
            {
                if (--indegree[next] == 0)
                    q.push(next);
            }
        }

        return ans.size() == kids ? ans : "";
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
