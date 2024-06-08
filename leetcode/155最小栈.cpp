#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    // ��������ջ��һ�����ڴ洢���ݣ���һ�����ڴ洢��Сֵ
    stack<int> data;
    stack<int> min;

    // ���캯������ʼ������ջ
    MinStack()
    {
        // ��ʼ��ջ,c++���ó�ʼ��ջ
    }

    // ��ջ������ͬʱ������Сֵջ
    void push(int val)
    {
        // ��Ԫ��������ջ
        data.push(val);

        // �����СֵջΪ�ջ�����Ԫ��С�ڵ��ڵ�ǰ��Сֵջ��ջ��Ԫ��
        if (min.empty() || val <= min.top()) // empty()��������Ƿ�Ϊ�գ��ǿվ���true
        {
            // ����Ԫ������Сֵջ
            min.push(val);
        }
        else
        {
            // ���򣬽���ǰ��Сֵջ��ջ��Ԫ���ٴ���ջ������ջ�Ĵ�Сһ��
            min.push(min.top());
        }
    }

    // ��ջ������ͬʱ������Сֵջ
    void pop()
    {
        // ����ջ����Сֵջͬʱ��ջ
        data.pop();
        min.pop();
    }

    // ��ȡջ��Ԫ��
    int top()
    {
        // ��������ջ��ջ��Ԫ��
        return data.top();
    }

    // ��ȡջ�е���Сֵ
    int getMin()
    {
        // ������Сֵջ��ջ��Ԫ��
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
        return min[size - 1]; // ������Ч
    }
};
