// 方法1 暴力枚举
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int l = nums.size();
        for (int i = 0; i < l; ++i)
        {
            for (int j = i + 1; j < l; ++j)
            {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }

        return {};
    }
};
// 方法2 哈希表
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashtable; // unordered_map是哈希表，具体操作看https://blog.csdn.net/weixin_45774972/article/details/113418453
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = hashtable.find(target - nums[i]); // auto是无类型关键字
            if (it != hashtable.end())
                return {it->second, i}; // if判断是否找到second是返回下标value，first是返回key值
            hashtable[nums[i]] = i;
        }
        return {}; // vector是要求返回值带{}
    }
};