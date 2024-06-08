#include <bits/stdc++.h>
using namespace std;

const int months[]{
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 初始化月份

int is_leap(int year) // 判断闰年
{
    if (year % 100 && year % 4 == 0 || year % 400 == 0) // 整百%400，不是先%100再%4
        return 1;
    return 0;
}

int get_month_day(int y, int m) // 算该月月份，这三段都是模板
{
    int res = months[m];
    if (m == 2)
        res += is_leap(y);
    return res;
}

int get_total_day(int y, int m, int d)
{
    int res = 0;
    for (int i = 1; i < y; i++) // 统计年份
        res += 365 + is_leap(i);
    for (int i = 1; i < m; i++)
        res += get_month_day(y, i);
    return res + d;
}

int main()
{
    int y1, m1, d1, y2, m2, d2;
    while (scanf("%04d%02d%02d", &y1, &m1, &d1) != -1)
    {
        scanf("%04d%02d%02d", &y2, &m2, &d2);
        printf("%d\n", abs(get_total_day(y1, m1, d1) - get_total_day(y2, m2, d2)) + 1);
    }
    return 0;
}