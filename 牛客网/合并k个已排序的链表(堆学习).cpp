#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    struct cp_heap
    {
        // 小根堆
        bool operator()(const ListNode *a, const ListNode *b) const
        {
            return a->val > b->val;
        }
        /*
        大根堆
         bool operator()(const ListNode* a, const ListNode* b) const{
            return a->val < b->val;
        }

        */
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // write code here
        priority_queue<ListNode *, vector<ListNode *>, cp_heap> heap;
        for (auto *h : lists)
            if (h != nullptr)
                heap.push(h);
        if (heap.empty())
            return nullptr;
        ListNode *h = heap.top(); // 当总头部
        heap.pop();
        ListNode *pre = h; // pre是串子
        if (pre->next != nullptr)
            heap.push(pre->next);
        while (!heap.empty())
        {
            ListNode *cur = heap.top();
            heap.pop();
            pre->next = cur;
            pre = cur;
            if (cur->next != nullptr)
                heap.push(cur->next);
        }
        return h;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
