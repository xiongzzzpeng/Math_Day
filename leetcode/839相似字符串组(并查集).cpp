#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// https://leetcode.cn/problems/similar-string-groups/
// �漰�����ϵĿ��ǲ��鼯

struct UnionFind
{
    vector<int> father;
    int set;

    // ��ʼ��
    UnionFind(int n) : father(n + 1, 0), set(n)
    {
        for (int i = 0; i <= n; i++)
            father[i] = i;
    }

    // �ݹ���ð汾find
    int find(int i)
    {
        if (i != father[i])
            father[i] = find(father[i]);
        return father[i];
    }

    // �ж��ǲ���ͬһ���ϴ�
    bool isSameSet(int x, int y)
    {
        return find(x) == find(y);
    }

    // �ϲ�x��y
    void unionSets(int x, int y)
    {
        father[find(x)] = find(y);
        set--;
    }
};

int numSimilarGroups(vector<string> &strs)
{
    int n = strs.size();
    int m = strs[0].size();
    UnionFind ui(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ui.find(i) != ui.find(j))
            {
                int diff = 0;
                for (int k = 0; k < m && diff < 3; k++)
                {
                    if (strs[i][k] != strs[j][k])
                        diff++;
                }
                if (diff == 0 || diff == 2)
                    ui.unionSets(i, j);
            }
        }
    }
    return ui.set;
}

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
