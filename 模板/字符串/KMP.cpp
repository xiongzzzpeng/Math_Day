#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

/**
 * 关键是构造前缀数组
 * Create函数就是在构造前缀数组
 * 一般都是模式串的前缀
 */
vector<int> Create(string &text, string &need) {
    int n = text.size(), m = need.size();

    string s = need + '#' + text;
    vector<int> pi(s.size());
    for (int i = 1; i < s.size(); i++) {
        int len = pi[i - 1];
        while (len && s[len] != s[i]) {
            len = pi[len - 1];
        }
        if (s[i] == s[len]) {
            pi[i] = len + 1;
            // 找到了模式串，返回偏移量
            // if (pi[i] == m) {
            //     return i - m * 2;
            // }
        }
    }
    return pi;
}

vector<int> KMP(string &text, string &pattern) {
    int m = pattern.size();

    vector<int> next(m);
    int c = 0;
    for (int i = 1; i < m; i++) {
        char v = pattern[i];
        while (c && pattern[c] != v) {
            c = next[c - 1];
        }
        if (pattern[c] == v) {
            c++;
        }
        next[i] = c;
    }

    vector<int> res;
    c = 0;
    for (int i = 0; i < text.size(); i++) {
        char v = text[i];
        while (c && pattern[c] != v) {
            c = next[c - 1];
        }
        if (pattern[c] == v) {
            c++;
        }
        if (c == m) {
            res.push_back(i - m + 1);
            c = next[c - 1];
        }
    }
    return res;
}

class Solution {
   public:
    int strStr(string haystack, string needle) {
        vector<int> ans = KMP(haystack, needle);

        return ans.size() == 0 ? -1 : ans[0];
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
