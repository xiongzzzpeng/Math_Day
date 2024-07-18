#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
#define lll __int128_t
typedef pair<int, int> PII;

vector<int> q(10010);

void que(int x)
{
    // hh是头，tt是尾
    int hh = 0, tt = -1;
    // 队尾插入
    q[++tt] = x;
    // 队首弹出
    q[hh++];
    // 判断是不是为空
    if (hh <= tt)
        q.empty(); // 是空
    // 取出队头
    int a = q[hh];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);

    return 0;
}
