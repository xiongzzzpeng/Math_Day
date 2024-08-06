#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

void Discreat(vector<int> &arr, int n) {
    vector<int> tmp(arr);
    sort(arr.begin(), arr.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
    }
}

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
