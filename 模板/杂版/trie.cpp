#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 1e6 + 10;

// cnt���Ե�ǰ������β��Ķ����ж��ٸ�
// idx�ǵ�ǰ�õ����ĸ��±꣬�±���0�ĵ��Ǹ��ڵ㣬���ǿս��
// son[i][y]��i�Ǵ������µĽ��,y����ĸ
int son[30][26], cnt[10], idx;

void insert(string s)
{
    int p = 0;
    for (auto L : s)
    {
        int u = L - 'a';
        // cnt[p]++;ͳ��ǰ׺�ͼ���һ��
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
