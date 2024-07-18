#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
typedef pair<int, int> PII;

// ���Լ��
int gcd(int a, int b)
{
    return __gcd(a, b);
}

// ��С������
int lcm(int a, int b)
{
    return abs(a * b) / gcd(a, b);
}

// �ж�����
bool prime(int x)
{
    if (x == 0 || x == 1)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

// �ҳ��������
void factor(int x)
{
    vector<int> cnt(10);
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i != 0)
            continue;
        cnt[i]++;
        if (i * i < x)
            cnt[x / i]++;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
    return 0;
}