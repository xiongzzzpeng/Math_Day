#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    getline(cin, n);
    int len = n.length();
    int ans = 0;
    for (int i = 0; i <= len - 2; i++) // 要考虑一下len-2这个条件
    {
        if (n[i] == n[i + 1] || n[i] == '?' || n[i + 1] == '?')
        {
            ans++;
            i++;
        }
    }
    printf("%d", ans);

    return 0;
}
