#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://atcoder.jp/contests/abc351/tasks/abc351_c

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> stk;
    for (int i = 0; i < n; i++)
    {
        int A;
        cin >> A;
        stk.push_back(A); // 队尾插入
        while (stk.size() >= 2 && stk[stk.size() - 2] == stk.back())
        {
            stk.pop_back(); // 队尾弹出
            stk.back()++;
        }
    }
    cout << stk.size();
    return 0;
}
