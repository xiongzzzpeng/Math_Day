#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100010;

int n;
int cnt[N], q[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &q[i]);
    int res = 1;
    for (int l = 1, r = 1; r <= n; r++)
    {
        cnt[q[r]]++;
        while (cnt[q[r]] > 1)
        {
            cnt[q[l]]--;
            l++;
        }
        res = max(res, r - l + 1);
    }
    printf("%d", res);
    return 0;
}
