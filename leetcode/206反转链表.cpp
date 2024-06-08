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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL; // 一个交换的作用，通过使用pre指针，我们可以确保在反转链表时不会丢失任何节点，并确保新的前向链接正确地建立起来。
        ListNode *next2 = NULL;
        while (head != NULL)
        {
            next2 = head->next;
            head->next = pre;
            pre = head;
            head = next2;
        }
        return pre;
    }
};