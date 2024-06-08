#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

void issue()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, f, k;
        cin >> n >> f >> k;
        f--;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int gt = 0, eq = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > a[f])
                gt++;
            else if (a[i] == a[f])
                eq++;
        }
        if (k <= gt)
            cout << "NO" << endl;
        else if (k >= gt + eq)
            cout << "YES" << endl;
        else
            cout << "MAYBE" << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    issue();
    return 0;
}
