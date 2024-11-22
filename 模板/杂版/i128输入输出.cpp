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

using i128 = __int128;

template <typename T>
inline T read() {
    T x = 0, f = 1;
    char ch = 0;
    for (; !isdigit(ch); ch = getchar()) {
        if (ch == '-') {
            f = -1;
        }
    }
    for (; isdigit(ch); ch = getchar()) {
        x = (x << 3) + (x << 1) + (ch - '0');
    }
    return x * f;
}

template <typename T>
inline void write(T x) {
    if (x < 0) {
        putchar('-'), x = -x;
    }
    if (x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

template <typename T>
inline void print(T x, char ed = '\n') {
    write(x), putchar(ed);
}

i128 qpow(i128 a, i128 b, i128 mod) {
    i128 res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

void Solve() {
    i128 n = read<i128>();
    write(n);
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
