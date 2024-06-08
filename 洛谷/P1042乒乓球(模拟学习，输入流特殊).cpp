#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 1e6 + 10;

// https://www.luogu.com.cn/problem/P1042

char str[N];
int cnt = 0;

void show(int n)
{
    int ml = 0, zjk = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (str[i] == 'W')
            ml++;
        if (str[i] == 'L')
            zjk++;
        if ((ml >= n || zjk >= n) && abs(ml - zjk) >= 2)
        {
            cout << ml << ":" << zjk << endl;
            ml = 0, zjk = 0;
        }
    }
    cout << ml << ":" << zjk << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    char ch;
    while (cin >> ch && ch != 'E') // 学习这个输入流
    {
        if (ch == 'W' || ch == 'L')
            str[cnt++] = ch;
    }

    show(11);
    cout << endl;
    show(21);

    return 0;
}
