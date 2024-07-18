#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// 求一段和的值，求sum = [l, r] = s[r] - s[l - 1]

// 后缀和
void su_add(vector<int> a)
{
    int i = a.size();
    vector<int> suf(i + 1);
    for (i; i >= 1; i--)
    {
        suf[i] += suf[i + 1] + a[i];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> s(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 前缀和初始化，s[i] = a[0] + a[1] ... + a[i]
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    cout << s[3] - s[1]; // 求[2, 3]的和
    return 0;
}
