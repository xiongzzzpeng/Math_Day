#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/
// 最小生成树：连接

class Solution
{
public:
    struct UnionFind
    {
        vector<int> father;
        int set;

        // 初始化
        UnionFind(int n) : father(n + 1, 0), set(n)
        {
            for (int i = 0; i <= n; i++)
            {
                father[i] = i;
            }
        }

        // 递归调用版本find
        int find(int i)
        {
            if (i != father[i])
            {
                father[i] = find(father[i]);
            }
            return father[i];
        }

        // 判断是不是同一个老大
        bool isSameSet(int x, int y)
        {
            return find(x) == find(y);
        }

        // 合并x跟y
        void unionSets(int x, int y)
        {
            int fx = find(x), fy = find(y);
            if (fx != fy)
            {
                father[fx] = fy;
            }
        }
    };

    struct GraphEdge
    {
        int u, v, w, id;
    };

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edge, vector<vector<int>> &queries)
    {
        sort(edge.begin(), edge.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        int k = edge.size();
        int m = queries.size();
        vector<GraphEdge> quest(m);
        for (int i = 0; i < m; i++)
        {
            quest[i] = {queries[i][0], queries[i][1], queries[i][2], i};
        }

        sort(quest.begin(), quest.end(), [](const GraphEdge &a, const GraphEdge &b)
             { return a.w < b.w; });

        UnionFind uf(n);
        vector<bool> ans(m);

        for (int i = 0, j = 0; i < m; i++)
        {
            // i是问题
            // j是边
            // 循环就是连接小于问题的边连通，一直到大于等于就停
            while (j < k && edge[j][2] < quest[i].w)
            {
                uf.unionSets(edge[j][0], edge[j][1]);
                j++;
            }
            ans[quest[i].id] = uf.isSameSet(quest[i].u, quest[i].v);
        }

        return ans;
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
