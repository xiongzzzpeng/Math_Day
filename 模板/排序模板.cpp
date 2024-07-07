#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 1e6 + 10;

// ����ģ��
// https://www.luogu.com.cn/problem/P1177

// ����ģ�壬���ܻ���O(n^2)
void quick_sort(vector<int> &q, int l, int r)
{
    if (l >= r)
        return;
    // �ֽ��,����ָ��
    int x = q[l], i = l - 1, j = r + 1;
    while (i < j)
    {
        // �������С��Ŀ��ֵ��������
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    // ��������
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

// �鲢����(O(n^2))
int tem[N];
void merge_sort(vector<int> &q, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + ((r - l) >> 1);
    // �ݹ�������ұ�
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    // �鲢,k�Ǽ�¼����
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tem[k++] = q[i++];
        else
            tem[k++] = q[j++];
    }
    // ��ʣ�µ�
    while (i <= mid)
        tem[k++] = q[i++];
    while (j <= r)
        tem[k++] = q[j++];
    // �û�
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tem[j];
}

// ��������,leetcode��
vector<int> findOrder(int num, vector<vector<int>> &pre)
{
    vector<vector<int>> graph(num); // �ڽӱ�
    vector<int> indegree(num, 0);   // ���
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

// ��������,��������
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
        int n, m; // n���㣬m����
        cin >> n >> m;
        vector<vector<int>> graph(n + 1); // ͼ
        vector<int> indegree(n + 1, 0);   // ���

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
