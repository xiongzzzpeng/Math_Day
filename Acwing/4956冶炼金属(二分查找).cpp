#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e9;

int main()
{
    int n;
    scanf("%d", &n);
    int o[n], x[n];
    int k = N;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &o[i], &x[i]);
        if (o[i] / x[i] < k)
            k = o[i] / x[i];
    }
    int l = 1, r = k;
    while (l < r)
    {
        int mid = l + ((r - l) >> 1);
        int i = 0;
        for (i = 0; i < n; i++)
        {
            if (o[i] / mid != x[i])
                break;
        }
        if (i == n)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << " " << k;
    return 0;
}
