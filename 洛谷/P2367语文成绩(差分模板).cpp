#include <bits/stdc++.h>
using namespace std;

// https://www.luogu.com.cn/problem/P2367
int main()
{
    int n, p;
    scanf("%d%d", &n, &p);
    vector<int> scors(n + 1, 0); // ��ʼ���ɼ�����
    vector<int> diff(n + 2, 0);  // �������
    for (int i = 1; i <= n; i++)
        scanf("%d", &scors[i]);

    // ���²��
    for (int i = 0; i < p; i++)
    {
        int l, r, val;
        cin >> l >> r >> val;
        diff[l] += val;
        diff[r + 1] -= val;
    }
    // ����ǰ׺��
    for (int i = 1; i <= n; i++)
    {
        diff[i] += diff[i - 1];
        scors[i] += diff[i];
    }
    int ans = scors[1];
    for (int i = 2; i <= n; i++)
        ans = min(ans, scors[i]);
    printf("%d\n", ans);
    return 0;
}