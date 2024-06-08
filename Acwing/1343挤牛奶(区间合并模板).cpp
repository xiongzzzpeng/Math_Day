#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> PII;
const int N = 5010;

PII segs[N]; // ���������
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &segs[i].first, &segs[i].second); // ��˵㣬 �Ҷ˵�
    sort(segs, segs + n);

    int res1 = 0, res2 = 0;

    // ����ϲ�ģ��
    int l = segs[0].first, r = segs[0].second;
    for (int i = 1; i < n; i++)
        if (segs[i].first <= r) // ��һ����˵�С����һ���ҵ�ʱ��
            r = max(r, segs[i].second);
        else
        {
            res1 = max(res1, r - l);
            res2 = max(res2, segs[i].first - r);   // ά�����䵽�ڶ�������ľ���
            l = segs[i].first, r = segs[i].second; // ����ά��������
        }
    res1 = max(res1, r - l);
    printf("%d %d", res1, res2);
    return 0;
}
