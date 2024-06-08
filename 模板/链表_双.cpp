#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

void add_r(vector<int> &e, vector<int> &l, vector<int> &r, int idx, int k, int x)
{
    // 在第k点右边插入
    // 像在k的左边插入直接调用l[k]
    e[k] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
}

void remove(vector<int> &e, vector<int> &l, vector<int> &r, int idx, int k)
{
    // 删除k的下一个结点
    r[l[k]] = r[k]; // 上一个结点的右边
    l[r[k]] = l[k]; // 下一个结点的左边
}

void oduble_ls(vector<int> &e, vector<int> &l, vector<int> &r)
{
    // l[i]i左边的点，r[i]是i右边的点
    int idx = 2;
    r[0] = 1, l[1] = 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);

    return 0;
}
