#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// 求一段和的值，求sum = [l, r] = s[r] - s[l - 1]
// 差分是前缀和的逆运算，原数组 a1, a2, a3...an 差分变为 b1, b2, b3...bn
// an = b1 + b2 + b3... + bn

// 一维前缀和
void one_presum(int n)
{
    vector<int> a(n + 1);
    vector<int> s(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 前缀和初始化，s[i] = a[0] + a[1] ... + a[i]
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    cout << s[3] - s[1]; // 求[2, 3]的和
}

// 二维前缀和公式
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
    // 找(2, 2)~(3, 3)的值
    // s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]
    cout << s[3][3] - s[2 - 1][3] - s[3][2 - 1] + s[2 - 1][2 - 1];
}

// 一维差分
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
    // 前缀和还原
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
