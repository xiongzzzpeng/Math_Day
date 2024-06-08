#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 不用额外空间方法
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode *a = headA, *b = headB;
        int dif = 0;
        while (a->next != NULL)
        {
            a = a->next;
            dif++;
        }
        while (b->next != NULL)
        {
            b = b->next;
            dif--;
        }
        if (a != b)
            return NULL;
        if (dif >= 0)
        {
            a = headA;
            b = headB;
        }
        else
        {
            a = headB;
            b = headA;
        }
        dif = abs(dif);
        while (dif-- != 0)
            a = a->next;
        while (a != b)
        {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};

// 哈希表方法
class Solution2
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> vist;
        ListNode *a = headA;
        while (a != NULL)
        {
            vist.insert(a);
            a = a->next;
        }
        a = headB;
        while (a != NULL)
        {
            if (vist.count(a))
                return a;
            a = a->next;
        }
        return NULL;
    }
};