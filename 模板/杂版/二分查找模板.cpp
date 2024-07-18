#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/find-smallest-letter-greater-than-target/description/
// ����ģ��
int low_bound(vector<int> &q, int target)
{
    // �����䣬 l����l��[l, size]����>target [0, r]����<target
    // ��˵������l = q.size() && r = -1��
    // ex��q.size() = 5�����һ���±���4��l = 5
    int l = 0, r = q.size() - 1;
    while (l <= r)
    {
        int mid = l + ((r - l) >> 1);
        if (q[mid] < target)
            l = mid + 1; // ��ʱ�ռ���Ϊ[mid + 1, r]
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