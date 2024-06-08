#include <bits/stdc++.h>
using namespace std;

int add(int a, int b) // 减法就是add(a,add(~b,1))
{
    // ans是无进位信息
    int ans = a;
    while (b != 0)
    {
        ans = a ^ b;
        // b：a和b相加的进位信息
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

// 除法没听

int main()
{

    return 0;
}