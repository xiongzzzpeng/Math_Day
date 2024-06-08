#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque
{
public:
    deque<int> deque; // 使用deque实现双向链表
    int size, limit;

    MyCircularDeque(int k)
    {
        size = 0;
        limit = k;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        else
        {
            deque.push_front(value); // 放入头部
            size++;
            return true;
        }
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        else
        {
            deque.push_back(value); // 放入尾部
            size++;
            return true;
        }
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        else
        {
            size--;
            deque.pop_front(); // 删除头部
            return true;
        }
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        else
        {
            size--;
            deque.pop_back(); // 删除尾部
            return true;
        }
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        else
            return deque.front(); // 得到头部
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return deque.back(); // 得到尾部
    }

    bool isEmpty()
    {
        return size == 0; // 空
    }

    bool isFull()
    {
        return size == limit; // 满
    }
};

// 循环队列写的
class MyCircularDeque2
{
public:
    // 使用 std::vector 作为循环双端队列的底层数据结构
    vector<int> data;
    // 指示队列头和尾的索引，size 记录当前元素个数，limit 记录队列容量上限
    int l, r, size, limit;

    // 构造函数，初始化队列
    MyCircularDeque2(int k)
    {
        data.resize(k);   // 调整底层数组大小为 k
        l = r = size = 0; // 初始化头、尾、和元素个数为 0
        limit = k;        // 初始化队列容量上限
    }

    // 在队头插入元素
    bool insertFront(int value)
    {
        if (isFull())
            return false; // 队列满，插入失败
        else
        {
            if (isEmpty())
            {
                l = r = 0; // 如果队列为空，头和尾都指向第一个元素
                data[0] = value;
            }
            else
            {
                l = (l == 0) ? (limit - 1) : (l - 1); // 否则更新头的位置
                data[l] = value;
            }
            size++;
            return true; // 插入成功
        }
    }

    // 在队尾插入元素
    bool insertLast(int value)
    {
        if (isFull())
            return false; // 队列满，插入失败
        if (isEmpty())
        {
            l = r = 0; // 如果队列为空，头和尾都指向第一个元素
            data[0] = value;
        }
        else
        {
            r = (r == limit - 1) ? 0 : (r + 1); // 否则更新尾的位置
            data[r] = value;
        }
        size++;
        return true; // 插入成功
    }

    // 从队头删除元素
    bool deleteFront()
    {
        if (isEmpty())
            return false; // 队列空，删除失败
        else
        {
            l = (l == (limit - 1)) ? 0 : (l + 1); // 更新头的位置
            size--;
            return true; // 删除成功
        }
    }

    // 从队尾删除元素
    bool deleteLast()
    {
        if (isEmpty())
            return false; // 队列空，删除失败
        else
        {
            r = (r == 0) ? (limit - 1) : (r - 1); // 更新尾的位置
            size--;
            return true; // 删除成功
        }
    }

    // 获取队头元素
    int getFront()
    {
        if (isEmpty())
            return -1; // 队列空，返回 -1
        else
            return data[l]; // 返回队头元素
    }

    // 获取队尾元素
    int getRear()
    {
        if (isEmpty())
            return -1; // 队列空，返回 -1
        else
            return data[r]; // 返回队尾元素
    }

    // 判断队列是否为空
    bool isEmpty()
    {
        return size == 0;
    }

    // 判断队列是否已满
    bool isFull()
    {
        return size == limit;
    }
};
