#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void heapInster(vector<int> &nums, int i)
    {
        while (nums[i] > nums[(i - 1) / 2])
        {
            swap(nums[i], nums[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void heapify(vector<int> &nums, int i, int size)
    {
        int l = i * 2 + 1;
        while (l < size)
        {
            int best = l + 1 < size && nums[l + 1] > nums[l] ? l + 1 : l;
            best = nums[best] > nums[i] ? best : i;
            if (best == i)
                break;
            swap(nums[best], nums[i]);
            i = best;
            l = i * 2 + 1;
        }
    }
    void heapsort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            heapInster(nums, i);
        int size = n;
        while (size > 1)
        {
            swap(nums[0], nums[--size]);
            heapify(nums, 0, size);
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        heapsort(nums);
        return nums;
    }
};