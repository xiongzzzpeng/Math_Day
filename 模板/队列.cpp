#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
#define lll __int128_t
typedef pair<int, int> PII;

vector<int> q(10010);

void que(int x)
{
    // hh��ͷ��tt��β
    int hh = 0, tt = -1;
    // ��β����
    q[++tt] = x;
    // ���׵���
    q[hh++];
    // �ж��ǲ���Ϊ��
    if (hh <= tt)
        q.empty(); // �ǿ�
    // ȡ����ͷ
    int a = q[hh];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);

    return 0;
}
