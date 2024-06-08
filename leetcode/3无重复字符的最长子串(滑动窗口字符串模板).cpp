#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/longest-substring-without-repeating-characters/
// �������ڣ��������ַ���������߽�һ���ǿ���һ�γ��ֵ�λ��
// �������ڣ�������ַ���ģ��

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int ans = 0;
        int last[256];
        fill(last, last + 256, -1);
        for (int l = 0, r = 0; r < n; r++)
        {
            // ��һ�γ��ֵ�λ�ú���߽�Ƚ�
            l = max(l, last[s[r]] + 1);
            ans = max(ans, r - l + 1);
            last[s[r]] = r;
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
