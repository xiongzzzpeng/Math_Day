#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    // ȡ��kλ,���±�0��ʼ
    cout << (n >> k & 1) << endl;
    // lowbit(x),����x�����һλ1 lowbit() = (x & -x)
    cout << lowbit(n);
    return 0;
}
