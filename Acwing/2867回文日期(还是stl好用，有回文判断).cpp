#include <bits/stdc++.h>
using namespace std;
#define ll long long

using namespace std;
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int date) // �ж������Ƿ�Ϸ�
{
    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;
    if (!day || month < 0 || month > 12)
        return false;
    if (month != 2 && day > months[month])
        return false;
    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) // ��������
        {
            if (day > 29)
                return false;
        }
        else
        {
            if (day > 28)
                return false;
        }
    }
    return true;
}
bool check1(string s) // �ж��Ƿ��ǻ�������
{
    int len = s.size();
    for (int i = 0, j = len - 1; i < j; i++, j--) // ˫ָ��
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}
bool check2(string s) // �ж��Ƿ���ABABBABA �͵Ļ�������
{
    if (check1(s)) // ���ȸ�����Ҫ������ĸ�ʽ
    {
        if (s[0] != s[2] || s[1] != s[3] || s[0] == s[1])
            return false;
        return true;
    }
}
int main()
{
    int date, flag = 0;
    cin >> date;
    for (int i = date + 1;; i++)
    {
        if (check(i))
        {
            string s = to_string(i);
            if (check1(s) && !flag) // �����������
            {
                cout << i << endl;
                flag = 1; // ���һ�£����������
            }
            if (check2(s)) // ���ABABBABA �͵Ļ�������
            {
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}
// ��������ʱд��
// bool check(int r)
// {
//     int year = r / 10000, month = r % 10000 / 100, day = r % 100;
//     if (month > 12 || month < 1)
//         return false;
//     if (day == 0)
//         return false;
//     if (month != 2)
//     {
//         if (day > days[month])
//             return false;
//     }
//     else
//     {
//         int leap = ((year % 100 && year % 4 == 0) || (year % 400 == 0));
//         if (day > days[month] + leap)
//             return false;
//     }
//     return true;
// }

// bool find_hw(int date)
// {
//     int res = 0, temp = date;
//     while (temp > 0)
//     {
//         res = res * 10 + temp % 10;
//         temp /= 10;
//     }
//     if (check(res) && res == date)
//         return true;
//     return false;
// }

// bool find_ab(int date)
// {
//     int year = date / 10000, month = date % 10000 / 100, day = date % 100;
//     int b = month / 10, a = month % 10;
//     if (find_hw(date) && (year / 1000 == a && year / 100 % 10 == b && year / 10 % 10 == a && year % 10 == b && year && a != b && day / 10 == b && day % 10 == a))
//         return true;
//     return false;
// }

// int main()
// {
//     int date, flag = 0;
//     cin >> date;
//     for (int i = date + 1;; i++)
//     {
//         if (find_hw(i) && flag == 0)
//         {
//             cout << i << endl;
//             flag = 1;
//         }
//         if (find_ab(i))
//         {
//             cout << i << endl;
//             return 0;
//         }
//     }
//     return 0;
// }
