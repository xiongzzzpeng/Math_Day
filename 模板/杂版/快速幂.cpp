#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// 快速幂(a的b次幂)
i64 qpow(i64 a, i64 b, int mod) {
    i64 res = 0;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
    }
    return res;
}

void issue() {
    i64 a, b;
    cin >> a >> b;
    cout << qpow(a, b, 1e9 +7) << endl;
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
        issue();
    }
    return 0;
}
