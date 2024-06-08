#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
const int N = 100010;
int h[N], w[N];

bool chack(int a)
{
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        num += (h[i] / a) * (w[i] / a); // num是巧克力的总数
        if (num >= k)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &h[i], &w[i]);
    int l = 1, r = 1e5;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (chack(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l;
    return 0;
}
