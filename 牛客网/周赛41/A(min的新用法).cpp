#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    if (b == min({a, b, c}))
        cout << min(a, c) - b;
    else
        cout << "0";
    return 0;
}
