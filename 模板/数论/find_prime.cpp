#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using i64 = long long;
using PII = pair<int, int>;
using PLL = pair<i64, i64>;
using u64 = unsigned long long;
using u32 = unsigned;

// 找到所有组成它prime
// O(sqrt(n))

void find_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        cout << n;
    }
}

void Solve() {
    int n;
    cin >> n;
    find_prime(n);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

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
