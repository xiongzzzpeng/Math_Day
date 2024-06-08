#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

// 多路并归，几个一起比较的题。是种思想不是模板
// https://www.acwing.com/problem/content/1264/

int a[N], d[N], l[N], spend[N]; // a是每个鱼塘第一次钓的鱼数，d是每分钟减少的鱼数，l是两个鱼塘的距离，spend在该鱼塘花的时间

int get(int k)
{
    return max(0, a[k] - d[k] * spend[k]);
}

int work(int n, int T) // 当前路线钓的鱼
{
    int res = 0;                    // 总鱼数
    memset(spend, 0, sizeof spend); // 每个鱼塘没花时间，所以要清

    for (int i = 0; i < T; i++)
    {
        int t = 1;
        for (int j = 2; j <= n; j++)
            if (get(t) < get(j))
                t = j;

        res += get(t);
        spend[t]++;
    }

    return res;
}

int main()
{
    int n, T;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &l[i]);
        l[i] += l[i - 1]; // 前缀和表示第一个鱼塘到当前鱼塘一共要多少时间
    }
    scanf("%d", &T);

    int res = 0;
    for (int i = 1; i <= n; i++)           // 枚举走哪条路线
        res = max(res, work(i, T - l[i])); // 路上花的时间

    printf("%d\n", res);
    return 0;
}