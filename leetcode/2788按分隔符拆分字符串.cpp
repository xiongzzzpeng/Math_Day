#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        vector<string> ans;
        for (const auto &w : words)
        {                        // 每次循环时，w会被赋值为words中的一个元素。
            istringstream ss(w); // 对象ss，并将w作为其输入字符串
            string s;
            while (getline(ss, s, separator)) // 使用getline函数从ss中读取数据到s中，直到遇到separator
            {
                if (!s.empty()) // 用于检查一个容器是否为空。如果容器中没有任何元素，则 empty() 返回 true；否则，返回 false。
                    ans.push_back(s);
            }
        }
        return ans;
    }
};
// 如果你有一个字符串 "123 456", 你可以使用 istringstream 来将这个字符串分割成两个部分
//  ss >> a >> b;  // 从ss中读取两个整数，a = 123, b = 456