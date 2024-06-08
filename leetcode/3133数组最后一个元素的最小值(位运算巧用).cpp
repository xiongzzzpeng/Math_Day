#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// 要把n中的第j个bit，填到x中的第i个比特，0填1不填
// 按位就是每个数一次&的结果要是x
// 要尽量小，就取n-1就行
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
