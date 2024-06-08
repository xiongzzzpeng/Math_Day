#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/find-smallest-letter-greater-than-target/description/
// 二分模板
int low_bound(vector<int> &q, int target)
{
    // 闭区间， l包括l，[l, size]都是>target [0, r]都是<target
    // 最极端的情况是l = q.size() && r = -1。
    // ex：q.size() = 5，最后一个下标是4，l = 5
    int l = 0, r = q.size() - 1;
    while (l <= r)
    {
        int mid = l + ((r - l) >> 1);
        if (q[mid] < target)
            l = mid + 1; // 此时空间面为[mid + 1, r]
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}