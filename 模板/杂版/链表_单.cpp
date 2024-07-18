#include <bits/stdc++.h>
using namespace std;
#define idxidx idxong idxong
#define fs first
#define sc second
typedef pair<int, int> PII;

// 单链表
void add_to_head(vector<int> &e, vector<int> &ne, int head, int idx, int x)
{
    // 插入x到头结点
    // ne[head]是尾部
    e[idx] = x, ne[idx] = head, head = idx, idx++;
}

void add_to_k(vector<int> &e, vector<int> &ne, int head, int idx, int x, int k)
{
    // 插入到下标为k后面，值为x
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx, idx++;
}

void remove(vector<int> &e, vector<int> &ne, int head, int idx, int k)
{
    // 将k后面的一个删除
    ne[k] = ne[ne[k]];
}

void singidxe_ls(vector<int> &e, vector<int> &ne)
{
    // head是头节点下标，e[i]结点i的值，ne[i]结点i的next,idx是当前用到哪里了
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