#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 画匠问题
// 如果符合要求的段 <= k，说明有画家工作量不够其他人多了，人均还能再小
// > k,说明画家人均少了，还可以再多

class Solution {
public:
    int splitArray(vector<int> &nums, int k) {
        ll l = 0, r = accumulate(nums.begin(), nums.end(), 0);

        auto check = [&](ll m) {
            int parts = 1;
            ll sum = 0;
            for (auto n : nums) {
                if (n > m)
                    return INT32_MAX;
                if (sum + n > m) {
                    parts++;
                    sum = n;
                } else {
                    sum += n;
                }
            }
            return parts;
        };

        while (l < r) {
            ll mid = l + ((r - l) >> 1);
            if (check(mid) <= k)
                r = mid;
            else
                l = mid + 1;
        }

        return r;
    }
};

void Solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
