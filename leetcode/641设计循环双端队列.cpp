#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque
{
public:
    deque<int> deque; // ʹ��dequeʵ��˫������
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
            deque.push_front(value); // ����ͷ��
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
            deque.push_back(value); // ����β��
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
            deque.pop_front(); // ɾ��ͷ��
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
            deque.pop_back(); // ɾ��β��
            return true;
        }
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        else
            return deque.front(); // �õ�ͷ��
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return deque.back(); // �õ�β��
    }

    bool isEmpty()
    {
        return size == 0; // ��
    }

    bool isFull()
    {
        return size == limit; // ��
    }
};

// ѭ������д��
class MyCircularDeque2
{
public:
    // ʹ�� std::vector ��Ϊѭ��˫�˶��еĵײ����ݽṹ
    vector<int> data;
    // ָʾ����ͷ��β��������size ��¼��ǰԪ�ظ�����limit ��¼������������
    int l, r, size, limit;

    // ���캯������ʼ������
    MyCircularDeque2(int k)
    {
        data.resize(k);   // �����ײ������СΪ k
        l = r = size = 0; // ��ʼ��ͷ��β����Ԫ�ظ���Ϊ 0
        limit = k;        // ��ʼ��������������
    }

    // �ڶ�ͷ����Ԫ��
    bool insertFront(int value)
    {
        if (isFull())
            return false; // ������������ʧ��
        else
        {
            if (isEmpty())
            {
                l = r = 0; // �������Ϊ�գ�ͷ��β��ָ���һ��Ԫ��
                data[0] = value;
            }
            else
            {
                l = (l == 0) ? (limit - 1) : (l - 1); // �������ͷ��λ��
                data[l] = value;
            }
            size++;
            return true; // ����ɹ�
        }
    }

    // �ڶ�β����Ԫ��
    bool insertLast(int value)
    {
        if (isFull())
            return false; // ������������ʧ��
        if (isEmpty())
        {
            l = r = 0; // �������Ϊ�գ�ͷ��β��ָ���һ��Ԫ��
            data[0] = value;
        }
        else
        {
            r = (r == limit - 1) ? 0 : (r + 1); // �������β��λ��
            data[r] = value;
        }
        size++;
        return true; // ����ɹ�
    }

    // �Ӷ�ͷɾ��Ԫ��
    bool deleteFront()
    {
        if (isEmpty())
            return false; // ���пգ�ɾ��ʧ��
        else
        {
            l = (l == (limit - 1)) ? 0 : (l + 1); // ����ͷ��λ��
            size--;
            return true; // ɾ���ɹ�
        }
    }

    // �Ӷ�βɾ��Ԫ��
    bool deleteLast()
    {
        if (isEmpty())
            return false; // ���пգ�ɾ��ʧ��
        else
        {
            r = (r == 0) ? (limit - 1) : (r - 1); // ����β��λ��
            size--;
            return true; // ɾ���ɹ�
        }
    }

    // ��ȡ��ͷԪ��
    int getFront()
    {
        if (isEmpty())
            return -1; // ���пգ����� -1
        else
            return data[l]; // ���ض�ͷԪ��
    }

    // ��ȡ��βԪ��
    int getRear()
    {
        if (isEmpty())
            return -1; // ���пգ����� -1
        else
            return data[r]; // ���ض�βԪ��
    }

    // �ж϶����Ƿ�Ϊ��
    bool isEmpty()
    {
        return size == 0;
    }

    // �ж϶����Ƿ�����
    bool isFull()
    {
        return size == limit;
    }
};
