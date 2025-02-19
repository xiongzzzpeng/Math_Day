#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 10010;

// https://www.luogu.com.cn/problem/P1601 加法
// https://www.luogu.com.cn/problem/P1303 乘法

bool compare(char s1[], char s2[])  // s1 >= s2返回true
{
    int u = strlen(s1), v = strlen(s2);
    if (u != v) return u > v;
    for (int i = 0; i < u; i++)
        if (s1[i] != s2[i]) return s1[i] > s2[i];
    return true;
}

// 高精度加法
string big_add(const string &a, const string &b) {
    string result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit_a = (i >= 0) ? (a[i] - '0') : 0;
        int digit_b = (j >= 0) ? (b[j] - '0') : 0;

        int sum = digit_a + digit_b + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');

        i--;
        j--;
    }

    reverse(result.begin(), result.end());
    return result;
}

// 高精度减法
string big_sub(const string &a, const string &b) {
    auto compare = [&](string &a, string &b) -> bool {
        if (a.size() != b.size()) return a.size() > b.size();
        return a >= b;
    };

    string A = a, B = b;
    bool negative = false;

    // 如果 a < b，则交换并标记为负数
    if (!compare(A, B)) {
        swap(A, B);
        negative = true;
    }

    string result;
    int borrow = 0;
    int i = A.size() - 1;
    int j = B.size() - 1;

    while (i >= 0 || j >= 0) {
        int digit_a = (i >= 0) ? (A[i] - '0') : 0;
        int digit_b = (j >= 0) ? (B[j] - '0') : 0;

        int diff = digit_a - digit_b - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_back(diff + '0');
        i--;
        j--;
    }

    // 去除前导零
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());

    // 如果为负数且结果不为0，添加负号
    if (negative && result != "0") result.insert(result.begin(), '-');

    return result;
}

// 高精度乘法
void Hight_mul(char *s1, char *s2, int *a, int *b, int *c) {
    ll la = strlen(s1), lb = strlen(s2);
    for (int i = 0; i < la; i++) a[la - i] = s1[i] - '0';
    for (int i = 0; i < lb; i++) b[lb - i] = s2[i] - '0';
    ll lc = la + lb;
    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            c[i + j - 1] += a[i] * b[j];
            c[i + j] += c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }
    }
    while (c[lc] == 0 && lc > 1) lc--;
    for (int i = lc; i > 0; i--) cout << c[i];
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int a[N] = {0}, b[N] = {0}, c[N]{0};
    char s1[N] = {'0'}, s2[N] = {'0'};
    cin >> s1 >> s2;
    Hight_mul(s1, s2, a, b, c);
    return 0;
}