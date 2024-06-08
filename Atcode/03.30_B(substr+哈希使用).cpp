#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://atcoder.jp/contests/abc347/tasks/abc347_b

int countSting(string s)
{
    unordered_set<string> set;
    int n = s.size();
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            set.insert(s.substr(i, j - i + 1)); // j - i + 1是子串长度，从i开始复制j-i+1长度的子串
    return set.size();
}

int main()
{
    string s;
    cin >> s;
    int res = countSting(s);
    cout << res;
    return 0;
}
