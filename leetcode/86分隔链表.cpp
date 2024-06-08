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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *leftHead = NULL, *LeftTail = NULL;
        ListNode *rightHead = NULL, *rightTail = NULL;
        ListNode *next = NULL;
        while (head != NULL)
        {
            next = head->next; // 记录环境，方便下一个
            head->next = NULL; // 断链
            if (head->val < x)
            {
                if (leftHead == NULL)
                    leftHead = head;
                else
                    LeftTail->next = head;
                LeftTail = head;
            }
            else
            {
                if (rightHead == NULL)
                    rightHead = head;
                else
                    rightTail->next = head;
                rightTail = head;
            }
            head = next; // 移动到下一个
        }
        if (leftHead == NULL)
            return rightHead;
        LeftTail->next = rightHead;
        return leftHead;
    }
};