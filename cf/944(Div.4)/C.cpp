#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://codeforces.com/contest/1971
// c,d��ͬһ�߾Ͳ��ཻ

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
            if (d > a && d < b) // ͬ�����
                cout << "NO\n";
            else
                cout << "YES\n";
        else // ȡ��������Ҳ����ȡ��
        {
            if (d > a && d < b)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
