#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

struct UnionFind
{
    vector<int> father;
    int set;
    vector<int> label; // 标签知道的是1，不知道是0, vector<bool> 会报错

    // 初始化
    UnionFind(int n, int first) : father(n + 2, 0), set(n), label(n + 2, 0)
    {
        for (int i = 0; i <= n; i++)
            father[i] = i;
        father[first] = 0;
        label[0] = 1; // 0是不知道，1是知道
    }

    // 递归调用版本find
    int find(int i)
    {
        if (i != father[i])
            father[i] = find(father[i]);
        return father[i];
    }

    // 判断是不是同一个老大
    bool isSameSet(int x, int y) { return find(x) == find(y); }

    // 合并x跟y
    void unionSets(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy)
        {
            father[fx] = fy;
            // |一下一个知道都知道
            label[fy] |= label[fx];
        }
    }
};

vector<int> findAllPeople(int n, vector<vector<int>> &meet, int first)
{
    UnionFind ui(n, first);
    // 比较器
    sort(meet.begin(), meet.end(),
         [](const vector<int> &a, const vector<int> &b)
         {
             return a[2] < b[2];
         });

    // 会议的场次
    int m = meet.size();

    // l到r是相同场次
    for (int l = 0, r; l < m;)
    {
        r = l;
        while (r + 1 < m && meet[l][2] == meet[r + 1][2])
            r++;

        for (int i = l; i <= r; i++)
        {
            ui.unionSets(meet[i][0], meet[i][1]);
        }

        // 拆开的操作
        for (int i = l; i <= r; i++)
        {
            int a = meet[i][0], b = meet[i][1];
            if (!ui.label[ui.find(a)])
                ui.father[a] = a;
            if (!ui.label[ui.find(b)])
                ui.father[b] = b;
        }

        l = r + 1;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (ui.label[ui.find(i)])
            ans.push_back(i);
    }

    return ans;
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
