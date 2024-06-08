#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 1e6 + 10;

// 字符串出现最长前缀就用trie
int son[N][26], idx, cnt[N];

void insert(string s)
{
    int p = 0;
    for (auto L : s)
    {
        int u = L - 'a';
        cnt[p]++;
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
    int n;
    cin >> n;
    int ans = 0;
    while (n--)
    {
        string s;
        cin >> s;
        insert(s);
    }
    for (int i = 1; i <= idx; i++)
        ans += cnt[i] * (cnt[i] - 1) / 2; // 组合数
    cout << ans << endl;
    return 0;
}
