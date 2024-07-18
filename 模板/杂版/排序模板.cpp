#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 1e6 + 10;

// 排序模板
// https://www.luogu.com.cn/problem/P1177

// 快排模板，可能会变成O(n^2)
void quick_sort(vector<int> &q, int l, int r)
{
    if (l >= r)
        return;
    // 分界点,两个指针
    int x = q[l], i = l - 1, j = r + 1;
    while (i < j)
    {
        // 后面的数小于目标值，就往后
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    // 处理两段
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

// 归并排序(O(n^2))
int tem[N];
void merge_sort(vector<int> &q, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + ((r - l) >> 1);
    // 递归排左边右边
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    // 归并,k是记录总数
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tem[k++] = q[i++];
        else
            tem[k++] = q[j++];
    }
    // 拿剩下的
    while (i <= mid)
        tem[k++] = q[i++];
    while (j <= r)
        tem[k++] = q[j++];
    // 拿回
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tem[j];
}

// 拓扑排序,leetcode版
vector<int> findOrder(int num, vector<vector<int>> &pre)
{
    vector<vector<int>> graph(num); // 邻接表
    vector<int> indegree(num, 0);   // 入度
    for (auto &edge : pre)
    {
        graph[edge[1]].push_back(edge[0]);
        indegree[edge[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < num; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> order;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        order.push_back(cur);

        for (int next : graph[cur])
        {
            if (--indegree[next] == 0)
                q.push(next);
        }
    }

    return order.size() == num ? order : vector<int>();
}

// 拓扑排序,输入流版
struct Order
{
    void findOrder(vector<vector<int>> &graph, vector<int> &indegree, vector<int> &ans, int n)
    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            for (auto next : graph[cur])
            {
                if (--indegree[next] == 0)
                    q.push(next);
            }
        }
    }

    void issue()
    {
        int n, m; // n个点，m条边
        cin >> n >> m;
        vector<vector<int>> graph(n + 1); // 图
        vector<int> indegree(n + 1, 0);   // 入度

        for (int i = 0; i < m; i++)
        {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            indegree[to]++;
        }

        vector<int> ans;
        findOrder(graph, indegree, ans, n);

        if (ans.size() == n)
        {
            for (int i = 0; i < n - 1; i++)
                cout << ans[i] << " ";
            cout << ans[n - 1] << endl;
        }
        else
            cout << "-1" << endl;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> q(n, 0);
    for (int i = 0; i < n; i++)
        cin >> q[i];
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
    return 0;
}
