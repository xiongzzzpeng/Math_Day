#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

/**
 * 闭区间二分模板
 */

int bitset_left(vector<int> a, int target) {
    int ans = -1;
    int lo = 0, hi = a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        // 找 <= 的数
        if (a[mid] <= target) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int bitset_right(vector<int> a, int target) {
    int ans = -1;
    int lo = 0, hi = a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        // 找 >= 的数
        if (a[mid] >= target) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}