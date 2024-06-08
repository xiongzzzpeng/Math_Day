#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        vector<string> ans;
        for (const auto &w : words)
        {                        // ÿ��ѭ��ʱ��w�ᱻ��ֵΪwords�е�һ��Ԫ�ء�
            istringstream ss(w); // ����ss������w��Ϊ�������ַ���
            string s;
            while (getline(ss, s, separator)) // ʹ��getline������ss�ж�ȡ���ݵ�s�У�ֱ������separator
            {
                if (!s.empty()) // ���ڼ��һ�������Ƿ�Ϊ�ա����������û���κ�Ԫ�أ��� empty() ���� true�����򣬷��� false��
                    ans.push_back(s);
            }
        }
        return ans;
    }
};
// �������һ���ַ��� "123 456", �����ʹ�� istringstream ��������ַ����ָ����������
//  ss >> a >> b;  // ��ss�ж�ȡ����������a = 123, b = 456