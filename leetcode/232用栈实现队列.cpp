#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    // stk_in: que ���Ԫ�ص�stk
    // stk_out: que popԪ�ص�stk
    stack<int> stk_in;
    stack<int> stk_out;

public:
    MyQueue() {}

    void push(int x) { stk_in.push(x); }

    // que pop: FIFO
    // case 1�� stk_empty, ������push��Ԫ�ض���stk_out�У�����ÿ��que
    // popԪ�ض���stk_outȡtopԪ��

    // case 2: has value,ֱ��ȡtopԪ��
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

        // popԪ��
        int res = stk_out.top();
        stk_out.pop();
        return res;
    }

    int peek()
    {
        // ȡque��ͷ
        int res = pop();
        // ��ԭ
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