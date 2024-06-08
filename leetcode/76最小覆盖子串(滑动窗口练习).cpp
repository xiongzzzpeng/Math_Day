#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/minimum-window-substring/?utm_source=LCUS
// ����������ϰ���Ϳ��ܲ��ܴ����ҵ�����û�е�����

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
            return "";
        int cnts[256];
        for (auto c : t)
            cnts[c]--; // �ñ��Ǵ����Ҫ��
        int len = INT_MAX;
        int start = 0; // ��¼��ʼ��λ��
        for (int l = 0, r = 0, debt = t.size(); r < s.size(); r++)
        {
            if (cnts[s[r]]++ < 0)
                debt--; // ����Ҫ���ַ�
            // �����
            if (debt == 0)
            {
                while (cnts[s[l]] > 0)
                    cnts[s[l++]]--; // ���ܲ�������
                if (r - l + 1 < len)
                {
                    len = r - l + 1;
                    start = l;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
