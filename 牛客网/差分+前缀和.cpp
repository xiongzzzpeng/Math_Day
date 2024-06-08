#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// ��һ�κ͵�ֵ����sum = [l, r] = s[r] - s[l - 1]
// �����ǰ׺�͵������㣬ԭ���� a1, a2, a3...an ��ֱ�Ϊ b1, b2, b3...bn
// an = b1 + b2 + b3... + bn

// һάǰ׺��
void one_presum(int n)
{
    vector<int> a(n + 1);
    vector<int> s(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // ǰ׺�ͳ�ʼ����s[i] = a[0] + a[1] ... + a[i]
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    cout << s[3] - s[1]; // ��[2, 3]�ĺ�
}

// ��άǰ׺�͹�ʽ
void two_presum(int n)
{
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> s(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    // ��(2, 2)~(3, 3)��ֵ
    // s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]
    cout << s[3][3] - s[2 - 1][3] - s[3][2 - 1] + s[2 - 1][2 - 1];
}

// һά���
void diff(int n)
{
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int l, r;
    cin >> l >> r;
    b[l] += 1;
    b[r + 1] -= 1;
    // ǰ׺�ͻ�ԭ
    for (int i = 1; i <= n; i++)
    {
        b[i] += b[i - 1];
        a[i] += b[i];
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    diff(n);
    return 0;
}
