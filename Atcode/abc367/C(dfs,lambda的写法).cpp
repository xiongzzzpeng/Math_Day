#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

void Solve() {
    int n, k;
    cin >> n >> k;

    vector<int> R(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }

    vector<int> a(n);

    auto dfs = [&](auto self, int i, int s) {
        if (i == n) {
            if (s % k == 0) {
                for (int i = 0; i < n; i++) {
                    cout << a[i] << " \n"[i == n - 1];
                }
            }
            return;
        }
        for (a[i] = 1; a[i] <= R[i]; a[i]++) {
            self(self, i + 1, a[i] + s);
        }
    };

    dfs(dfs, 0, 0);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
