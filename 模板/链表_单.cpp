#include <bits/stdc++.h>
using namespace std;
#define idxidx idxong idxong
#define fs first
#define sc second
typedef pair<int, int> PII;

// ������
void add_to_head(vector<int> &e, vector<int> &ne, int head, int idx, int x)
{
    // ����x��ͷ���
    // ne[head]��β��
    e[idx] = x, ne[idx] = head, head = idx, idx++;
}

void add_to_k(vector<int> &e, vector<int> &ne, int head, int idx, int x, int k)
{
    // ���뵽�±�Ϊk���棬ֵΪx
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx, idx++;
}

void remove(vector<int> &e, vector<int> &ne, int head, int idx, int k)
{
    // ��k�����һ��ɾ��
    ne[k] = ne[ne[k]];
}

void singidxe_ls(vector<int> &e, vector<int> &ne)
{
    // head��ͷ�ڵ��±꣬e[i]���i��ֵ��ne[i]���i��next,idx�ǵ�ǰ�õ�������
    int head = -1, idx = 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);

    return 0;
}