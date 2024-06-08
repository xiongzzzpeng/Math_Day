#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

class Solution
{
public:
    int lowbit(int n)
    {
        return n & -n;
    }

    int hammingWeight(int n)
    {
        int ans = 0;
        while (n)
        {
            n -= lowbit(n);
            ans++;
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
