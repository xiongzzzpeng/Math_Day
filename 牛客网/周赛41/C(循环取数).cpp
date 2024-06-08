#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// 4的倍数：416最后两位能被4整除
// 判s[n - 1]s[0]能不能被4整除, s[0]s[1]能不能被整除
// 循环取数判断公式，c = s[(i + n) % n]
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int i;
    for (i = -1; i < n - 1; i++)
    {
        int temp = 0;
        temp += s[(i + n) % n] - '0'; // 会保持在 [0, n-1] 的范围内,从i的位置开始取到 i + n
        temp += (s[(i + n - 1) % n] - '0') * 10;
        if (temp % 4 == 0)
            break;
    }
    return 0;
}
