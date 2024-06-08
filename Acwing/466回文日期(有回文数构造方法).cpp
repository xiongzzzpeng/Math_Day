#include <bits/stdc++.h>
using namespace std;
#define ll long long

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int r)
{
    int year = r / 10000, month = r % 10000 / 100, day = r % 100;
    if (month < 1 || month > 12)
        return false;
    if (day == 0)
        return false;
    if (month != 2)
    {
        if (day > days[month])
            return false;
    }
    else
    {
        int leap = ((year % 100 && year % 4 == 0) || (year % 400 == 0));
        if (day > days[month] + leap)
            return false;
    }
    return true;
}

int main()
{
    int date1, date2;
    scanf("%d%d", &date1, &date2);
    int res = 0;

    for (int i = 0; i < 10000; i++) // 只用遍历前四个就行
    {
        int l = i, r = i;
        for (int j = 0; j < 4; j++)
            r = r * 10 + l % 10, l /= 10; // 构造回文日期，也是回文数构造方法
        if (r >= date1 && r <= date2 && check(r))
            res++;
    }
    printf("%d", res);

    return 0;
}
