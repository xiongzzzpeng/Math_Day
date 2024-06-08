// ����1 ����ö��
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
// ����2 ��ϣ��
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashtable; // unordered_map�ǹ�ϣ�����������https://blog.csdn.net/weixin_45774972/article/details/113418453
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = hashtable.find(target - nums[i]); // auto�������͹ؼ���
            if (it != hashtable.end())
                return {it->second, i}; // if�ж��Ƿ��ҵ�second�Ƿ����±�value��first�Ƿ���keyֵ
            hashtable[nums[i]] = i;
        }
        return {}; // vector��Ҫ�󷵻�ֵ��{}
    }
};