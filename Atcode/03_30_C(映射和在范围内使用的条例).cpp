#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200010;

ll pl[N];
ll a, b, n, max1;

int main()
{
    scanf("%lld%lld%lld", &n, &a, &b);
    int r = a + b;
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &pl[i]);
        pl[i] = (pl[i] - 1) % r + 1; // ���࣬+1��Ϊ��ӳ����1-a�ķ�Χ��
    }
    sort(pl + 1, pl + 1 + n);
    if (pl[n] - pl[1] + 1 <= a) // ��ζ�����е����ڶ����԰�����һ������Ϊa�����������ڡ�
    {
        printf("Yes");
        return 0;
    }
    for (ll i = 2; i <= n; i++)
        max1 = max(max1, pl[i] - pl[i - 1] + 1); // ���ȱ����
    if (r - max1 <= a)                           // �����õ���a�죬�������õ���b
        return printf("Yes"), 0;
    printf("No");
    return 0;
}
