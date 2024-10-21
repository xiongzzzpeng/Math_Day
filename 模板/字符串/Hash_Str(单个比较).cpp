#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using i64 = long long;
using PII = pair<int, int>;
using PLL = pair<i64, i64>;
using u64 = unsigned long long;
using u32 = unsigned;

// 比较单个的内部
// 单个hash = hash[i - 1] * base + s[i] - 'a' + 1
// s[i-j] = hash[j] - hash[i - 1] * base^(j - i + 1)
class Hash {
   public:
    Hash(string &s) : p(MAXN, 0), hash(MAXN, 0) {
        p[0] = 1;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] * base;
        }
        hash[0] = s[0] - 'a' + 1;
        for (int i = 1; i < n; i++) {
            hash[i] = hash[i - 1] * base + s[i] - 'a' + 1;
        }
    }

    u64 hash_val(int l, int r) {
        u64 ans = hash[r];
        if (l > 0) {
            ans -= hash[l - 1] * p[r - l + 1];
        }
        return ans;
    }

   private:
    const int MAXN = 100005;
    const int base = 1e9 + 7;
    vector<u64> p, hash;
};

class Solution {
   public:
    int strStr(string s1, string s2) {
        Hash s1_hash(s1);
        Hash s2_hash(s2);

        u64 total = s2_hash.hash_val(0, s2.size() - 1);

        for (int l = 0, r = s2.size() - 1; r < s1.size(); l++, r++) {
            if (s1_hash.hash_val(l, r) == total) {
                return l;
            }
        }
        return -1;
    }
};

void Solve() {}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

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
