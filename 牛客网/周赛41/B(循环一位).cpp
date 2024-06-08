#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://ac.nowcoder.com/acm/contest/80742/B
// 前k位不变，后面n - k位左移一位就行

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (k == 1 || k > n)
        return cout << "-1", 0;
    for (int i = 0; i < n - k; i++)
        cout << a[i] << " ";
    for (int i = n - k + 1; i < n; i++)
        cout << a[i] << " ";
    cout << a[n - k];
    return 0;
}
