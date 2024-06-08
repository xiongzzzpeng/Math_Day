#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/minimum-length-of-anagram-concatenation/description/
// 模拟

class Solution
{
public:
    int minAnagramLength(string s)
    {
        int n = s.size();
        // k是因子
        for (int k = 1; k <= n / 2; k++)
        {
            if (n % k != 0)
                continue;
            array<int, 26> cnt0{}; // array是容器，int，26个
            for (int j = 0; j < k; j++)
            {
                cnt0[s[j] - 'a']++; // 统计数目
            }
            for (int i = k * 2; i <= n; i += k) // 去查找
            {
                array<int, 26> cnt{};
                for (int j = i - k; j < i; j++)
                    cnt[s[j] - 'a']++;
                if (cnt != cnt0)
                    goto next;
            }
            return k;
        next:;
        }
        return n;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
