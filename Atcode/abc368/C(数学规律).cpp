#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

void Solve() {
    ll T = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        T += h / 5 * 3;
        h %= 5;

        while (h > 0) {
            T++;
            h -= T % 3 ? 1 : 3;
        }
    }

    cout << T << endl;
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