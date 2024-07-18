#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 10010;

// https://www.luogu.com.cn/problem/P1601 �ӷ�
// https://www.luogu.com.cn/problem/P1303 �˷�

bool compare(char s1[], char s2[]) // s1 >= s2����true
{
    int u = strlen(s1), v = strlen(s2);
    if (u != v)
        return u > v;
    for (int i = 0; i < u; i++)
        if (s1[i] != s2[i])
            return s1[i] > s2[i];
    return true;
}

// �߾��ȼӷ�
void Hight_add(char *s1, char *s2, int *a, int *b, int *c)
{
    ll la = strlen(s1), lb = strlen(s2);
    // ת����,a[0]��b[0]��ûʹ��
    for (int i = 0; i < la; i++)
        a[la - i] = s1[i] - '0'; // ����
    for (int i = 0; i < lb; i++)
        b[lb - i] = s2[i] - '0';
    ll lc = max(la, lb) + 1; // ��1��ʼ
    for (int i = 1; i <= lc; i++)
    {
        c[i] += a[i] + b[i];
        c[i + 1] = c[i] / 10;
        c[i] = c[i] % 10;
    }
    if (c[lc] == 0 && lc > 0)
        lc--; // ɾ��ǰ��0
    for (int i = lc; i > 0; i--)
        cout << c[i];
    cout << endl;
}

// �߾��ȼ���
void Hight_sub(char *s1, char *s2, int *a, int *b, int *c)
{
    char s3[N] = {'0'};
    int flag = 0;
    if (!compare(s1, s2)) // s1 < s2,swap
    {
        flag = 1;
        strcpy(s3, s1);
        strcpy(s1, s2);
        strcpy(s2, s3);
    }
    ll la = strlen(s1), lb = strlen(s2);
    for (int i = 0; i < la; i++)
        a[la - i] = s1[i] - '0';
    for (int i = 0; i < lb; i++)
        b[lb - i] = s2[i] - '0';
    ll lc = max(la, lb);
    for (int i = 1; i <= lc; i++)
    {
        if (a[i] < b[i])
        {
            a[i + 1]--;
            a[i] += 10;
        }
        c[i] = a[i] - b[i];
    }
    while (c[lc] == 0 && lc > 1)
        lc--;
    if (flag == 1)
        cout << "-";
    for (int i = lc; i > 0; i--)
        cout << c[i];
    cout << endl;
}

// �߾��ȳ˷�
void Hight_mul(char *s1, char *s2, int *a, int *b, int *c)
{
    ll la = strlen(s1), lb = strlen(s2);
    for (int i = 0; i < la; i++)
        a[la - i] = s1[i] - '0';
    for (int i = 0; i < lb; i++)
        b[lb - i] = s2[i] - '0';
    ll lc = la + lb;
    for (int i = 1; i <= la; i++)
    {
        for (int j = 1; j <= lb; j++)
        {
            c[i + j - 1] += a[i] * b[j];
            c[i + j] += c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }
    }
    while (c[lc] == 0 && lc > 1)
        lc--;
    for (int i = lc; i > 0; i--)
        cout << c[i];
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int a[N] = {0}, b[N] = {0}, c[N]{0};
    char s1[N] = {'0'}, s2[N] = {'0'};
    cin >> s1 >> s2;
    Hight_mul(s1, s2, a, b, c);
    return 0;
}