#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    int x;
    cin >> x;
    if (x < 0 || (x % 10 == 0 && x != 0))
        cout << "false";
    ll ans = 0;
    int num = x;
    while (x != 0)
    {
        ans = ans * 10 + x % 10;
        x = x / 10;
    }
    if (ans == num)
        cout << "true";
    else
        cout << "false";
}