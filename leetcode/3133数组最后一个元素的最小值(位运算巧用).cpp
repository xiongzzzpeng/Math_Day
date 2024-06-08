#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// Ҫ��n�еĵ�j��bit���x�еĵ�i�����أ�0��1����
// ��λ����ÿ����һ��&�Ľ��Ҫ��x
// Ҫ����С����ȡn-1����
// https://leetcode.cn/problems/minimum-array-end/

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        n--;
        long long ans = x;
        int i = 0, j = 0;
        while (n >> j)
        {
            if ((ans >> i & 1) == 0)
            {
                ans |= (long long)(n >> j & 1) << i;
                j++;
            }
            i++;
        }
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
