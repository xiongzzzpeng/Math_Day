#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> PII;
const int N = 5010;

PII segs[N]; // 区间的数组
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &segs[i].first, &segs[i].second); // 左端点， 右端点
    sort(segs, segs + n);

    int res1 = 0, res2 = 0;

    // 区间合并模板
    int l = segs[0].first, r = segs[0].second;
    for (int i = 1; i < n; i++)
        if (segs[i].first <= r) // 下一个左端点小于上一个右的时候
            r = max(r, segs[i].second);
        else
        {
            res1 = max(res1, r - l);
            res2 = max(res2, segs[i].first - r);   // 维护区间到第二个区间的距离
            l = segs[i].first, r = segs[i].second; // 更新维护的区间
        }
    res1 = max(res1, r - l);
    printf("%d %d", res1, res2);
    return 0;
}
