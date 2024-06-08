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
    vector<int> father, size;

    // ��ʼ��
    UnionFind(int n) : father(1000010, 0), size(1000010, 1)
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

    /*

        int find(int i)
        {
            // ģ��ջ
            vector<int> stack;
            while (i != father[i])
            {
                stack.push_back(i);
                i = father[i];
            }
            while (!stack.empty())
            {
                father[stack.back()] = i;
                stack.pop_back();
            }
            return i;
        }

    */

    // �ж��ǲ���ͬһ���ϴ�
    bool isSameSet(int x, int y)
    {
        return find(x) == find(y);
    }

    // �ϲ�x��y
    void unionSets(int x, int y)
    {
        father[find(x)] = find(y);
        // С������Ĳ�����һ���ò���
        // int fx = find(x);
        // int fy = find(y);
        // if (fy != fx)
        // {
        //     if (size[fx] >= size[fy])
        //     {
        //         size[fx] += size[fy];
        //         father[fy] = fx;
        //     }
        //     else
        //     {
        //         size[fy] += size[fx];
        //         father[fx] = fy;
        //     }
        // }
    }
};

void issue()
{
    int n, m;
    cin >> n >> m;
    // ���ã�����һ����С��n������
    UnionFind ui(n);
    while (m--)
    {
        int a, x, y;
        cin >> a >> x >> y;
        if (a == 2)
        {
            if (ui.isSameSet(x, y))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
        else
            ui.unionSets(x, y);
    }
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
