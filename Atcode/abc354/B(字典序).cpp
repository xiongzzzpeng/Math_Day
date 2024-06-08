#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int sum = 0;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        int c;
        cin >> c;
        sum += c;
    }
    // ×ÖµäĞò¿ÉÒÔÓÃsortÅÅĞò
    sort(s.begin(), s.end());
    cout << s[sum % n] << endl;
    return 0;
}
