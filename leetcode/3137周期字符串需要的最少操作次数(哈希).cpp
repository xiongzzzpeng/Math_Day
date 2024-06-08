#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/minimum-number-of-operations-to-make-word-k-periodic/description/
// �ҳ����ִ��������Ӵ��������ٵ��滻�˾���

class Solution
{
public:
    int minimumOperationsToMakeKPeriodic(string word, int k)
    {
        int n = word.size(), mx = 0;
        unordered_map<string, int> cnt;
        for (int i = k; i <= n; i += k) // ��k��ʼ����
            mx = max(mx, ++cnt[word.substr(i - k, k)]);
        return n / k - mx;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
