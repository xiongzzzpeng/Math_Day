#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int help[100010];

    void merge(vector<int> &nums, int l, int mid, int r)
    {
        int i = l, a = l, b = mid + 1;
        while (a <= mid && b <= r)
            help[i++] = nums[a] <= nums[b] ? nums[a++] : nums[b++];
        while (a <= mid)
            help[i++] = nums[a++];
        while (b <= r)
            help[i++] = nums[b++];
        for (i = l; i <= r; i++)
            nums[i] = help[i];
    }
    void mergeSort(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return;
        int mid = l + ((r - l) >> 1);
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};