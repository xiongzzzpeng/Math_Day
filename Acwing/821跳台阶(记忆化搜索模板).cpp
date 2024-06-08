#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 20;

int n;
int mem[N];

// https://www.acwing.com/problem/content/823/
//  ¼ÇÒä»¯ËÑË÷Ä£°å
int dfs(int x)
{
    if (mem[x])
        return mem[x];
    int sum = 0;

    if (x == 1)
        sum = 1;
    else if (x == 2)
        sum = 2;
    else
        sum = dfs(x - 1) + dfs(x - 2);

    mem[x] = sum;
    return sum;
}

int main()
{
    scanf("%d", &n);
    int res = dfs(n);
    cout << res;
    return 0;
}