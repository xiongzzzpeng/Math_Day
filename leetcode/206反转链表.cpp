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
        ListNode *pre = NULL; // һ�����������ã�ͨ��ʹ��preָ�룬���ǿ���ȷ���ڷ�ת����ʱ���ᶪʧ�κνڵ㣬��ȷ���µ�ǰ��������ȷ�ؽ���������
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