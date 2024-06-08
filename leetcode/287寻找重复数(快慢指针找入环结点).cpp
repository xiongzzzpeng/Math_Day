#include <bits/stdc++.h>
using namespace std;
#define ll long long

// ����ָ�����뻷���
// slow��һ����fast������������fast����ͷ
// slowһ����fastһ���������Ǵ�

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];       // ��ָ���ƶ�һ��
        int fast = nums[nums[0]]; // ��ָ���ƶ�����
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // �ڶ�����
        fast = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};