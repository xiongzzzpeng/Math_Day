#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && n == (n & (-n)); // È¡×î×ó±ßµÄ1
    }
};