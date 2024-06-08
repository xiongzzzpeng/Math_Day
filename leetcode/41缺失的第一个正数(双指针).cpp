#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://leetcode.cn/problems/first-missing-positive/
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int l = 0, r = nums.size();
        // l��߶�����i+1��������Զ����lλ�õ����������ܲ���l++
        // ��rһֱ���Ҿ�һֱ������������õ���������1-r�ǿ����ռ�ȫ�ģ�ÿ�������ռ�һ��
        // �����������Ԥ�ڱ��r--
        while (l < r)
        {
            if (nums[l] == l + 1)
                l++;
            else if (nums[l] <= l || nums[l] > r || nums[nums[l] - 1] == nums[l]) // �����������
                                                                                  // ���������±���6��ֵ��7��λ�õ�ֵһ������ô������������Ϊ���ظ���
                swap(nums[l], nums[--r]);
            else
                swap(nums[l], nums[nums[l] - 1]);
        }
        return l + 1;
    }
};