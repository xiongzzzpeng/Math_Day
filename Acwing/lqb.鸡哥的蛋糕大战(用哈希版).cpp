#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> PII;
set<PII> st; // 只能用set，不能用unordered_set来构建哈希

int a, b;
int mx = INT_MIN;

int main()
{
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        int res = 0;
        string s = to_string(i);
        for (auto ch : s)
        {
            if (ch == '0' || ch == '6' || ch == '9')
                res++;
            else if (ch == '8')
                res += 2;
        }
        mx = max(mx, res);
        st.insert({mx, i});
    }
    for (auto ch : st)
    {
        if (ch.first == mx)
        {
            printf("%d", ch.second);
            break;
        }
    }
    return 0;
}
