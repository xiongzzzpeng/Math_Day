#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    string capitalizeTitle(string title)
    {
        istringstream ss(title); // ���ո�ָ��ַ�
        string ans, s;
        while (ss >> s)
        {
            if (!ans.empty())
                ans += ' ';
            if (s.size() > 2)
            {
                ans += toupper(s[0]); // ������ĸ��ɴ�д
                s = s.substr(1);      // �����Ӵ�
            }
            for (char c : s)
            {
                ans += tolower(c); // ʣ�����ĸ��Сд
            }
        }
        return ans;
    }
};