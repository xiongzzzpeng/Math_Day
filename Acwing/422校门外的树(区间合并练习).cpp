#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> PII;
const int N = 110;

// 同牛客的差分+前缀和是一道题

PII tree[N];
int n, len;

void marge(int l, int r)
{
    int res = len + 1;
    for (int i = 1; i < n; i++)
        if (tree[i].first <= r)
            r = max(r, tree[i].second);
        else
        {
            res -= r - l + 1;
            l = tree[i].first, r = tree[i].second;
        }
    res -= r - l + 1;
    printf("%d", res);
}

int main()
{
    scanf("%d%d", &len, &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &tree[i].first, &tree[i].second);
    sort(tree, tree + n);
    marge(tree[0].first, tree[0].second);
    return 0;
}
