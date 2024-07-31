#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int l = 1, r = piles[1]; // r是数组里面的最大值
        auto check = [&](int spend) {
            ll x = 0;
            for (auto temp : piles) {
                x += (temp + spend - 1) / spend;
            }
            return x;
        };

        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (check(mid) <= h) {
                r = mid;
            } else
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
