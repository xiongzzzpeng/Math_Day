#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 用栈实现
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        stack<int> num;
        ListNode *a = head;
        while (a != NULL)
        {
            int i = a->val;
            num.push(i);
            a = a->next;
        }
        a = head;
        while (a != NULL)
        {
            if (num.top() != a->val)
                return false;
            num.pop();
            a = a->next;
        }
        return true;
    }
};

// 不用栈实现
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 中点就是slow，中点开始往右的逆序
        ListNode *pre = slow;
        ListNode *cur = slow->next;
        ListNode *next = NULL;
        pre->next = NULL;
        while (cur != NULL)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        bool ans = true;
        ListNode *left = head;
        ListNode *right = pre;
        while (left != NULL && right != NULL)
        {
            if (left->val != right->val)
            {
                ans = false;
                break;
            }
            left = left->next;
            right = right->next;
        }
        cur = pre->next;
        pre->next = NULL;
        next = NULL;
        while (cur != NULL)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return ans;
    }
};