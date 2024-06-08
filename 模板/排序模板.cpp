#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 1e6 + 10;

// 排序模板
// https://www.luogu.com.cn/problem/P1177

// 快排模板，可能会变成O(n^2)
void quick_sort(vector<int> &q, int l, int r)
{
    if (l >= r)
        return;
    // 分界点,两个指针
    int x = q[l], i = l - 1, j = r + 1;
    while (i < j)
    {
        // 后面的数小于目标值，就往后
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    // 处理两段
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

// 归并排序(O(n^2))
int tem[N];
void merge_sort(vector<int> &q, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + ((r - l) >> 1);
    // 递归排左边右边
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    // 归并,k是记录总数
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tem[k++] = q[i++];
        else
            tem[k++] = q[j++];
    }
    // 拿剩下的
    while (i <= mid)
        tem[k++] = q[i++];
    while (j <= r)
        tem[k++] = q[j++];
    // 拿回
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tem[j];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> q(n, 0);
    for (int i = 0; i < n; i++)
        cin >> q[i];
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
    return 0;
}
