#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countKeyChanges(string s)
    {
        int ans = 0;
        for (int i = 1; i < s.size(); i++)
        {
            ans += (s[i - 1] & 31) != (s[i] & 31); // ��д��ĸ��Сд��ĸ�����Ƶĺ�5λ��һ���ģ�&31����ȡ����λ
        }
        return ans;
    }
};