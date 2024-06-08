#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://www.acwing.com/problem/content/4658/
//  1���ò����ÿ��λ�ñ�+�˶��ٴ�
//  2��c1*a1.....cn*an���������򲻵�ʽ����c������a���������С����������������

const int N = 1e5 + 10;
ll s[N], w[N];
int n, m;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    scanf("%d", &m);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        s[l]++;
        s[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
        s[i] += s[i - 1]; // ����������
    ll sum1 = 0;
    for (int i = 1; i <= n; i++)
    {
        sum1 += (ll)w[i] * s[i];
    }
    sort(s + 1, s + n + 1); // ��Ϊ0��λ����0������õ���n+1
    sort(w + 1, w + n + 1);
    ll sum2 = 0; // ���ֵ
    for (int i = 1; i <= n; i++)
        sum2 += (ll)w[i] * s[i];
    printf("%lld", sum2 - sum1);
    return 0;
}
