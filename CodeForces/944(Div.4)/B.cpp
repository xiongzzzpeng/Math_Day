#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://codeforces.com/contest/1971/problem/B
// 题意是全部字母都不在位置上，第一个不同的移到第一位就行

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        string t = s;
        int j = 0;
        sort(s.begin(), s.end());
        if (s[0] == s[s.size() - 1])
        {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < s.size(); i++)
            if (t[i] != t[0])
                j = i;
        swap(t[0], t[j]);
        cout << "YES\n";
        cout << t << endl;
    }
    return 0;
}
