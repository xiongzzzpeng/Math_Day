#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

using u64 = unsigned long long;

// 快速幂(a的b次幂)
template <class T>
constexpr T qpow(T a, u64 b, T res = 1) {
    for (; b != 0; b /= 2, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

void issue() {
    i64 a, b;
    cin >> a >> b;
    cout << qpow<i64>(a, b, 1e9 + 7) << endl;
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
