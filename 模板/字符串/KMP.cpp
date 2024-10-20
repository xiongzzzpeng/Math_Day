#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

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
