#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 100010;

ll n, d;
ll v[N], a[N];

int main()
{
    scanf("%lld%lld", &n, &d);
    for (int i = 1; i < n; i++)
        scanf("%lld", &v[i]);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]); // �ͼ�
    ll ans = 0, oil = 0, dist = 0;
    int p = a[1];
    for (int i = 2; i <= n; i++)
    {
        dist += v[i - 1];                // ����һ����ľ���
        ll t = (dist + d - 1) / d - oil; // ��Ҫ������������ȡ��
        ans += t * p;                    // ������Ҫ�ļ۸�
        oil += t;                        // ����ʣ�������
        p = min((ll)p, a[i]);            // ��С�ļ۸�
    }
    printf("%lld\n", ans);
    return 0;
}
/*
    �Ȳ����ͣ�����Ҫ�����͵���һ����
    ����һ�����Բ��͵ĵط��ӣ�ѡ��۸���͵�
    �磺2��3��1����������˵ĵط�������1�ӵ������ܵ�3�ĵ�
*/