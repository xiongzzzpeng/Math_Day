#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7, N = 2e5;

// https//ac.nowcoder.com/acm/contest/78807/D

char s[N];

int main()
{
    int n;
    cin >> n;
    cin >> (s + 1);
    ll ans = 0, cnt = 0; // ans�Ǵ𰸣�cnt�ǵ�ǰ�кö��ַ�����һ�����϶�����һ��ż����ϳ�ż��
    for (int i = 1; i <= n; i++)
    {
        if (s[i] - '0' == 0)
        {
            ans = (ans + cnt + 1) % mod;
            cnt = cnt * 2 % mod; // ��ͷ��β��Ҫ����
        }
        else if ((s[i] - '0') & 1)     // ������ʱ�򣬲�����
            cnt = (cnt * 2 + 1) % mod; // ��ͷ��β + ����
        else
        {
            ans = (ans + cnt + 1) % mod;
            cnt = (cnt * 2 + 1) % mod;
        }
    }
    cout << ans;
    return 0;
}
