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
                    if (it % i == 1 && set.insert(i).second) // 因为系统默认建立的是<int, bool>
                        flag = true;                         // 有就是false，没有就是false，没有就插入
            }
        }
        return set.size();
    }
};