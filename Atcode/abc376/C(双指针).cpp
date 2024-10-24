#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = -1;
    int i = n - 1, j = n - 2;
    while (i >= 0) {
        if (a[i] <= b[j]) {
            i--, j--;
            continue;
        }
        if (ans == -1) {
            ans = a[i];
            i--;
        } else {
            cout << -1 << "\n";
            return;
        }
    }
    cout << ans << "\n";
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
