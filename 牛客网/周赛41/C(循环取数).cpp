#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// 4�ı�����416�����λ�ܱ�4����
// ��s[n - 1]s[0]�ܲ��ܱ�4����, s[0]s[1]�ܲ��ܱ�����
// ѭ��ȡ���жϹ�ʽ��c = s[(i + n) % n]
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
        temp += s[(i + n) % n] - '0'; // �ᱣ���� [0, n-1] �ķ�Χ��,��i��λ�ÿ�ʼȡ�� i + n
        temp += (s[(i + n - 1) % n] - '0') * 10;
        if (temp % 4 == 0)
            break;
    }
    return 0;
}
