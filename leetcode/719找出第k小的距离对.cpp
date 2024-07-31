#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 二分答案找数对的典题
// mid差值
// >= k对数时说明右边的数大了
// <= k对数时说明左边的数小了

class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int nl = 0, nr = nums.back() - nums[0];

        auto check = [&](int mid) {
            int cnt = 0;
            for (int l = 0, r = 0; l < nums.size(); l++) {
                while (r + 1 < nums.size() && nums[r + 1] - nums[l] <= mid)
                    r++;
                cnt += r - l;
            }

            return cnt;
        };

        while (nl < nr) {
            int mid = nl + ((nr - nl) >> 1);
            if (check(mid) >= k) {
                nr = mid;
            } else {
                nl = mid + 1;
            }
        }

        return nr;
    }
};

void Solve() {
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++)
        cin >> h[i];

    ll l = 0, r = 0;
    for (ll n : h) {
        r = max(n, r);
    }

    auto check = [&](ll m, ll max) {
        for (int i = 0; i < N; i++) {
            if (m <= h[i])
                m -= h[i] - m;
            else {
                m += m - h[i];
            }
            if (m < 0) {
                return false;
            }
            if (m >= max) {
                return true;
            }
        }

        return true;
    };

    int max = r;
    while (l < r) {
        int mid = l + ((r - l) >> 1);
        if (check(mid, max))
            r = mid;
        else
            l = mid + 1;
    }

    cout << r << endl;
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
