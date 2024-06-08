#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    // 声明两个栈，一个用于存储数据，另一个用于存储最小值
    stack<int> data;
    stack<int> min;

    // 构造函数，初始化两个栈
    MinStack()
    {
        // 初始化栈,c++不用初始化栈
    }

    // 入栈操作，同时更新最小值栈
    void push(int val)
    {
        // 将元素入数据栈
        data.push(val);

        // 如果最小值栈为空或者新元素小于等于当前最小值栈的栈顶元素
        if (min.empty() || val <= min.top()) // empty()检查容器是否为空，是空就是true
        {
            // 将新元素入最小值栈
            min.push(val);
        }
        else
        {
            // 否则，将当前最小值栈的栈顶元素再次入栈，保持栈的大小一致
            min.push(min.top());
        }
    }

    // 出栈操作，同时更新最小值栈
    void pop()
    {
        // 数据栈和最小值栈同时出栈
        data.pop();
        min.pop();
    }

    // 获取栈顶元素
    int top()
    {
        // 返回数据栈的栈顶元素
        return data.top();
    }

    // 获取栈中的最小值
    int getMin()
    {
        // 返回最小值栈的栈顶元素
        return min.top();
    }
};

class MinStack2
{
public:
    const int MAXl = 10001;
    vector<int> data;
    vector<int> min;
    int size;
    MinStack2()
    {
        data.resize(MAXl);
        min.resize(MAXl);
        size = 0;
    }

    void push(int val)
    {
        data[size] = val;
        if (size == 0 || min[size - 1] >= val)
            min[size] = val;
        else
            min[size] = min[size - 1];
        size++;
    }

    void pop()
    {
        size--;
    }

    int top()
    {
        return data[size - 1];
    }

    int getMin()
    {
        return min[size - 1]; // 避免无效
    }
};
