#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 2e5 + 10;

// https://atcoder.jp/contests/abc350/tasks/abc350_c
// 给数排序

PII a[N];
int num[N], pos[N]; // pos存放对应的数组
int n, k;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        pos[num[i]] = i;
    }

    int ans = 0, temp = 0;
    for (int r = 1; r <= n; r++)
    {
        if (num[r] != r)
        {
            ans++;
            temp = num[r];
            a[k++] = {r, pos[r]};
            swap(num[r], num[pos[r]]);
            swap(pos[temp], pos[r]);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < k; i++)
        cout << a[i].fs << " " << a[i].sc << "\n";
    return 0;
}
