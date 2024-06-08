#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 2e5 + 10;

int n, k;
string s;
int nex[N][27]; // 一个预处理，从nex[i][j] 从i开始第一个字符j出现的位置

void ycl() // 查询某个字符在字符串中出现的位置的预处理模板
{
    for (int i = n + 1; i >= 1; i--)
    {
        for (int j = 0; j <= 25; j++)
            if (i == n + 1)
                nex[i][j] = n + 1;
            else
                nex[i][j] = nex[i + 1][j];
        nex[i][s[i] - 'A'] = i;
    }
}

int fd(int l, string &p)
{
    int first = 1;
    for (auto ch : p)
    {
        if (first)
            l = nex[l][ch - 'A'];
        else
            l = nex[l + 1][ch - 'A'];
        first = 0;
        if (l == n + 1)
            return l;
    }
    return l;
}

int main()
{
    cin >> n >> k >> s;
    s = " " + s; // 从下标1开始的处理
    ycl();
    string ac = "ACCEPT", wa = "WA";
    ll ans = 0;
    for (int l = 1; l <= n; l++)
    {
        int r1 = fd(l, ac), r2 = fd(l, wa);
        if (r1 == n + 1)
            continue;
        r1 = max(r1, l + k - 1);
        ans = ans + (ll)max(r2 - r1, 0);
    }
    cout << ans;
    return 0;
}
