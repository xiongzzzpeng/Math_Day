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

// 判断大数是不是prime
// O(10 * log(len(x))^3)

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

vector<i128> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool miller_rabin(i128 n) {
    if (n < 3 || n % 2 == 0) {
        return n == 2;
    }
    i128 u = n - 1, t = 0;
    while (u % 2 == 0) {
        u /= 2, ++t;
    }
    for (auto a : p) {
        if (n == a) {
            return 1;
        }
        if (n % a == 0) {
            return 0;
        }
        i128 v = qpow(a, u, n);
        if (v == 1) {
            continue;
        }
        i128 s = 1;
        for (; s <= t; ++s) {
            if (v == n - 1) {
                break;
            }
            v = v * v % n;
        }
        if (s > t) return 0;
    }
    return 1;
}

void Solve() {
    i128 n;
    n = read<i128>();
    if (miller_rabin(n))
        puts("Yes");
    else
        puts("No");
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    i128 T;
    T = read<i128>();
    while (T--) {
        Solve();
    }
    return 0;
}
