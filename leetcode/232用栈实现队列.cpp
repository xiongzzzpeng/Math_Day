#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    // stk_in: que 添加元素的stk
    // stk_out: que pop元素的stk
    stack<int> stk_in;
    stack<int> stk_out;

public:
    MyQueue() {}

    void push(int x) { stk_in.push(x); }

    // que pop: FIFO
    // case 1： stk_empty, 将最先push的元素丢到stk_out中，这样每次que
    // pop元素都从stk_out取top元素

    // case 2: has value,直接取top元素
    int pop()
    {
        if (stk_out.empty())
        {
            while (!stk_in.empty())
            {
                stk_out.push(stk_in.top());
                stk_in.pop();
            }
        }

        // pop元素
        int res = stk_out.top();
        stk_out.pop();
        return res;
    }

    int peek()
    {
        // 取que队头
        int res = pop();
        // 还原
        stk_out.push(res);
        return res;
    }

    bool empty() { return stk_in.empty() && stk_out.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */