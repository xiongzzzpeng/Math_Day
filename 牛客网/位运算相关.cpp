#include <bits/stdc++.h>
using namespace std;

int add(int a, int b) // ��������add(a,add(~b,1))
{
    // ans���޽�λ��Ϣ
    int ans = a;
    while (b != 0)
    {
        ans = a ^ b;
        // b��a��b��ӵĽ�λ��Ϣ
        b = (a & b) << 1;
        a = ans;
    }
    return ans;
}

int multiply(int a, int b)
{
    int ans = 0;
    while (b != 0)
    {
        if ((b & 1) != 0)
        {
            ans = add(ans, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return ans;
}

// ����û��

int main()
{

    return 0;
}