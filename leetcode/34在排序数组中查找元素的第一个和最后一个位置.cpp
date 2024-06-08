#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int leftBorder = getLeft(nums, target);
        int rightBorder = getRight(nums, target);
        if (leftBorder == -2 || rightBorder == -2)
            return {-1, -1};
        if (rightBorder - leftBorder > 1)
            return {leftBorder + 1, rightBorder - 1};
        return {-1, -1};
    }

private:
    int getRight(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, rightBorder = -2;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[mid] > target)
                right = mid - 1;
            else
            {
                left = mid + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
    int getLeft(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, leftBorder = -2;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[mid] >= target)
            {
                right = mid - 1;
                leftBorder = right;
            }
            else
                left = mid + 1;
        }
        return leftBorder;
    }
};