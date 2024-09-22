#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
using i64 = long long;
using PII = pair<int, int>;
using PLL = pair<i64, i64>;
using u64 = unsigned long long;
using u32 = unsigned;

void Solve() {
    int N, Q;
    cin >> N >> Q;

    string s;
    cin >> s;

    auto check = [&](int p) { return p >= 0 && p + 2 < N && s[p] == 'A' && s[p + 1] == 'B' && s[p + 2] == 'C'; };

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += check(i);
    }

    while (Q--) {
        int x;
        char c;
        cin >> x >> c;
        x--;

        for (int i = x - 2; i <= x; i++) {
            ans -= check(i);
        }
        s[x] = c;
        for (int i = x - 2; i <= x; i++) {
            ans += check(i);
        }

        cout << ans << endl;
    }
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
