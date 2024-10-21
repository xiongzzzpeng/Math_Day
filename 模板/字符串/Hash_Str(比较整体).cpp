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

// 字符串哈希
// 复杂样本转换成数字
// 比较每个整体用法
class Hash {
   public:
    u64 value(string &s) {
        u64 ans = v(s[0]);
        for (int i = 1; i < s.size(); i++) {
            ans = ans * base + v(s[i]);
        }
        return ans;
    }

   private:
    const int base = 1e9 + 7;

    int v(char c) {
        // 0 - 1 1 - 2..Z - 36 a - 37
        if (c >= 0 || c <= 9) {
            return c - 'A' + 1;
        } else if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 11;
        } else {
            return c - 'a' + 37;
        }
    }
};

void Solve() {
    int n;
    cin >> n;

    Hash hash;
    vector<u64> nums;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        nums.emplace_back(hash.value(s));
    }

    sort(nums.begin(), nums.end());

    int ans = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            ans++;
        }
    }
    cout << ans << endl;
}

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
