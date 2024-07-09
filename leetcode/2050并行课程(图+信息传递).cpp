#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// https://leetcode.cn/problems/parallel-courses-iii/description/
// ͼ+��Ϣ����

class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &rel, vector<int> &time)
    {
        vector<vector<int>> graph(n + 1);
        vector<int> in(n + 1);
        vector<int> cost(n + 1);

        for (auto &edge : rel)
        {
            graph[edge[0]].push_back(edge[1]);
            in[edge[1]]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (!in[i])
                q.push(i);
        }

        int ans = 0;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            cost[cur] += time[cur - 1];
            ans = max(ans, cost[cur]);

            for (auto &next : graph[cur])
            {
                cost[next] = max(cost[cur], cost[next]);
                if (--in[next] == 0)
                    q.push(next);
            }
        }
        return ans;
    }
};

void issue()
{
    Solution solver;

    int n = 5;

    // ��������֮��Ĺ�ϵ
    vector<vector<int>> rel = {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};

    // ����ÿ����������ʱ��
    vector<int> time = {1, 2, 3, 4, 5};

    // ����minimumTime��������ӡ���
    int result = solver.minimumTime(n, rel, time);
    cout << "Minimum time to complete all tasks: " << result << endl;
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
    // cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
