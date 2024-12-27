#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void Solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<int> q(k);
    for (int i = 0; i < k; i++) {
        cin >> q[i];
    }

    for (int x : a) {
        if (q.size() == n) {
            cout << 1;
        } else if (q.size() == n - 1) {
            cout << !binary_search(q.begin(), q.end(), x);
        } else {
            cout << 0;
        }
    }
    cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
