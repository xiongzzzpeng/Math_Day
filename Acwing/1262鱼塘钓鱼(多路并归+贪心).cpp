#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

// ��·���飬����һ��Ƚϵ��⡣����˼�벻��ģ��
// https://www.acwing.com/problem/content/1264/

int a[N], d[N], l[N], spend[N]; // a��ÿ��������һ�ε���������d��ÿ���Ӽ��ٵ�������l�����������ľ��룬spend�ڸ���������ʱ��

int get(int k)
{
    return max(0, a[k] - d[k] * spend[k]);
}

int work(int n, int T) // ��ǰ·�ߵ�����
{
    int res = 0;                    // ������
    memset(spend, 0, sizeof spend); // ÿ������û��ʱ�䣬����Ҫ��

    for (int i = 0; i < T; i++)
    {
        int t = 1;
        for (int j = 2; j <= n; j++)
            if (get(t) < get(j))
                t = j;

        res += get(t);
        spend[t]++;
    }

    return res;
}

int main()
{
    int n, T;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &l[i]);
        l[i] += l[i - 1]; // ǰ׺�ͱ�ʾ��һ����������ǰ����һ��Ҫ����ʱ��
    }
    scanf("%d", &T);

    int res = 0;
    for (int i = 1; i <= n; i++)           // ö��������·��
        res = max(res, work(i, T - l[i])); // ·�ϻ���ʱ��

    printf("%d\n", res);
    return 0;
}