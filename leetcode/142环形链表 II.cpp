#include <bits/stdc++.h>
// https://leetcode.cn/problems/linked-list-cycle-ii/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 快慢指针，1、快两步，慢一步。2、相遇快到头，慢停留。3、快一步，慢一步。4、相遇就是
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return NULL;
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while (slow != fast)
        {
            if (fast->next == NULL || fast->next->next == NULL)
                return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};