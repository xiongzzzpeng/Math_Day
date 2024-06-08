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

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = NULL, *cur = NULL;
        int carry = 0;
        for (int sum, val; l1 != NULL || l2 != NULL;
             l1 = l1 == NULL ? NULL : l1->next, l2 = l2 == NULL ? NULL : l2->next) // ÅÐ¶ÏÌõ¼þ
        {
            sum = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + carry;
            val = sum % 10;
            carry = sum / 10;
            if (ans == NULL)
            {
                ans = new ListNode(val);
                cur = ans;
            }
            else
            {
                cur->next = new ListNode(val);
                cur = cur->next;
            }
        }
        if (carry == 1)
            cur->next = new ListNode(1);
        return ans;
    }
};
