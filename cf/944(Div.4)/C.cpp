#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://codeforces.com/contest/1971
// c,d在同一边就不相交

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        if (c > a && c < b)
            if (d > a && d < b) // 同边情况
                cout << "NO\n";
            else
                cout << "YES\n";
        else // 取反，下面也跟着取反
        {
            if (d > a && d < b)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
