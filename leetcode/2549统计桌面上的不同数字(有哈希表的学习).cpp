#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distinctIntegers(int n)
    {
        unordered_set<int> set;
        set.insert(n);
        bool flag = true;
        while (flag)
        {
            flag = false;
            unordered_set<int> prive;
            prive = set;
            for (auto it : prive)
            {
                for (int i = 1; i <= n; i++)
                    if (it % i == 1 && set.insert(i).second) // ��ΪϵͳĬ�Ͻ�������<int, bool>
                        flag = true;                         // �о���false��û�о���false��û�оͲ���
            }
        }
        return set.size();
    }
};