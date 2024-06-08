#include <bits/stdc++.h>
using namespace std;

// https://www.luogu.com.cn/problem/P4231
const int MAXN = 10000005;

vector<long long> arr(MAXN, 0);

int n, m;

// �Ȳ����в��ģ��
void set1(int l, int r, int s, int e, int d) // l��r�ң�s���eĩ�d����
{
    arr[l] += s;
    arr[l + 1] += d - s;
    arr[r + 1] -= d + e;
    arr[r + 2] += e;
}

// ��ֵ������ǰ׺��
void build()
{
    for (int i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
    }
}

int main()
{

    while (cin >> n >> m)
    {
        for (int i = 0, l, r, s, e; i < m; i++)
        {
            cin >> l >> r >> s >> e;
            set1(l, r, s, e, (e - s) / (r - l)); // d���㷨
        }
        build();
        long long max1 = 0, xor_sum = 0;
        for (int i = 1; i <= n; i++)
        {
            max1 = max(max1, arr[i]);
            xor_sum ^= arr[i];
        }
        cout << xor_sum << " " << max1 << endl;
    }

    return 0;
}
