#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 自己创队列写
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        const int MAXN = 2001;
        TreeNode *queue[MAXN];
        int l, r;
        vector<vector<int>> ans;
        if (root != nullptr)
        {
            l = r = 0;
            queue[r++] = root;
            while (l < r)
            { // 队列里还有东西
                int size = r - l;
                vector<int> level;
                for (int i = 0; i < size; i++)
                {
                    TreeNode *cur = queue[l++];
                    level.push_back(cur->val);
                    if (cur->left != nullptr)
                    {
                        queue[r++] = cur->left;
                    }
                    if (cur->right != nullptr)
                    {
                        queue[r++] = cur->right;
                    }
                }
                ans.push_back(level);
            }
        }
        return ans;
    }
};

// 用封装的队列
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<vector<int>> res; // 存放每一层的节点值
        if (root != NULL)
            que.push(root);
        while (!que.empty())
        {
            vector<int> tmp; // 临时数组用于存放当前层的节点值
            for (int i = que.size(); i > 0; --i)
            {
                root = que.front();
                que.pop();
                tmp.push_back(root->val);
                if (root->left != NULL)
                    que.push(root->left);
                if (root->right != NULL)
                    que.push(root->right);
            }
            res.push_back(tmp); // 将当前层的节点值数组加入结果数组中
        }
        return res;
    }
};