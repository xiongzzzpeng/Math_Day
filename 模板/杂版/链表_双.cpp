#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

void add_r(vector<int> &e, vector<int> &l, vector<int> &r, int idx, int k, int x)
{
    // �ڵ�k���ұ߲���
    // ����k����߲���ֱ�ӵ���l[k]
    e[k] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
}

void remove(vector<int> &e, vector<int> &l, vector<int> &r, int idx, int k)
{
    // ɾ��k����һ�����
    r[l[k]] = r[k]; // ��һ�������ұ�
    l[r[k]] = l[k]; // ��һ���������
}

void oduble_ls(vector<int> &e, vector<int> &l, vector<int> &r)
{
    // l[i]i��ߵĵ㣬r[i]��i�ұߵĵ�
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
