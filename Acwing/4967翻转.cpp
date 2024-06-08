#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1000010;

char str[N], s[N];

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        /* code */
        scanf("%s%s", str, s);
        int size = strlen(s);
        int i = 0, res = 0, flag = 0;
        while (i < size)
        {
            /* code */
            if (s[i] != str[i])
            {
                if (i - 1 >= 0 && i + 1 < size && s[i - 1] == str[i] && s[i + 1] == str[i])
                    s[i] = str[i], res++, i += 1;
                else
                {
                    flag = 1;
                    puts("-1");
                    break;
                }
            }
            else
                i++;
        }
        if (!flag)
            printf("%d\n", res);
    }
    return 0;
}
/*
    有三个性质
    1、00或11则锁死，不操作
    2、从左到右操作或从右到左操作，结果不变
    3、操作不可逆
    操作
    1、s与t不相同就操作。
    2、s与t相同就不操作。
*/