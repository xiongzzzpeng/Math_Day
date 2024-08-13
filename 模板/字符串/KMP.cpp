#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

struct KMP {
    string tmp; // 目标串
    vector<int> next;

    KMP(const string &pat) : tmp(pat), next(md_next(pat)) {}

    // 在文本串中找目标串的开头位置，并记录所有符合条件的位置
    vector<int> strStr(const string &text) {
        int n = text.size(), m = tmp.size();
        int x = 0; // 文本串中的当前位置
        int y = 0; // 目标串中的当前位置

        vector<int> matches; // 记录所有匹配位置

        while (x < n) {
            if (text[x] == tmp[y]) {
                x++, y++;
                if (y == m) {
                    matches.push_back(x - y);
                    y = next[y]; // 回溯到下一个可能的匹配位置
                }
            } else {
                if (y == 0) {
                    x++;
                } else {
                    y = next[y];
                }
            }
        }

        return matches;
    }

private:
    // 计算 next 数组
    vector<int> md_next(const string &s) {
        int m = s.size();

        vector<int> next(m + 1);
        next[0] = -1;
        if (m == 1) {
            return next;
        }

        next[1] = 0;

        int i = 2;
        int cn = 0;
        while (i <= m) {
            if (s[i - 1] == s[cn]) {
                next[i++] = ++cn;
            } else if (cn > 0) {
                cn = next[cn];
            } else {
                next[i++] = 0;
            }
        }

        return next;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        KMP kmp(needle);

        vector<int> a = kmp.strStr(haystack);
        int n = a.size();

        if (n == 0)
            return -1;

        return a[0];
    }
};

void Solve() {
    string s1 = "leetcode", s2 = "leeto";
    Solution text;

    cout << text.strStr(s1, s2);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
