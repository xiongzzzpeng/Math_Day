#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 1e6 + 10;

// cnt是以当前这个点结尾存的儿子有多少个
// idx是当前用到了哪个下标，下标是0的点是根节点，又是空结点
// son[i][y]，i是从上往下的结点,y是字母
int son[30][26], cnt[10], idx;

void insert(string s)
{
    int p = 0;
    for (auto L : s)
    {
        int u = L - 'a';
        // cnt[p]++;统计前缀就加这一个
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string str)
{
    int p = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        insert(s);
        cout << query(s) << " ";
    }
    return 0;
}
