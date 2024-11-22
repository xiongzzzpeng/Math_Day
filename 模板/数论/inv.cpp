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

// 逆元：必须 a|b能整除 mod必须是质数 b和mod互斥
// b的逆元 inv(b) = b ** (mod - 2) % mod
// a | b = ((a % mod) * inv(b)) % mod

i64 qpow(i64 a, i64 b, i64 mod) {
    i64 res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

i64 inv(i64 a, i64 b, i64 mod) {
    i64 res = qpow(b, mod - 2, mod);
    return ((a % mod) * res) % mod;
}

// (1 | n!)的值
i64 fac_inv(i64 n, int mod) {
    const int mx = 1000;  // 初始值

    vector<i64> fac(mx + 1);
    fac[1] = 1;
    for (int i = 2; i <= mx; i++) {
        fac[i] = (1LL * i * fac[i - 1]) % mod;
    }

    vector<i64> res(mx + 1);
    res[mx] = qpow(fac[mx], mod - 2, mod);
    for (int i = mx - 1; i >= n; i--) {
        res[i] = (1LL * (i + 1) * res[i + 1]) % mod;
    }
    return res[n];
}

// 求的是[1, n]在整数在模mod意义下的乘法逆元
vector<i64> line_inv(i64 n, i64 mod) {
    vector<i64> res(n + 1);
    res[1] = 1;
    for (int i = 2; i <= n; i++) {
        res[i] = (mod - res[mod % i] * (mod / i) % mod);
    }
    return res;
}

void Solve() {
    const int mod = 1e9 + 7;

    i64 a = 1;
    for (int i = 2; i <= 8; i++) {
        a = (a * i) % mod;
    }
    cout << (((a * fac_inv(4, mod)) % mod) * fac_inv(4, mod)) % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen("zcy.in", "r", stdin);
    freopen("zcy.out", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
