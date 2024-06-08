// https://www.nowcoder.com/practice/bc25055fb97e4a0bb564cb4b214ffa92
#include <bits/stdc++.h>
using namespace std;

const int N = 501;

long long arr[N], help[N];

// 时间复杂度n*logn
void merge(int l, int r, int mid)
{
    int i = l, a = l, b = mid + 1; // i是管辅助数组的，a，b是管归并数组的，a是左半边，b右半边
    while (a <= mid && b <= r)
    {
        help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    }
    while (a <= mid)
    { // 有个越界，不越界的添加到后面去
        help[i++] = arr[a++];
    }
    while (b <= r)
    {
        help[i++] = arr[b++];
    }
    for (i = l; i <= r; i++)
        arr[i] = help[i];
}

void mergeSort(int l, int r)
{
    if (l == r)
        return;
    int mid = l + ((r - l) >> 1);
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, r, mid);
}

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
// 64 位输出请用 printf("%lld")