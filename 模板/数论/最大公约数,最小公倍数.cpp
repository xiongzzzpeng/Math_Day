#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 最大公约数 (辗转相除) O(log a ^ 3)
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, (a % b));
}

// 最小公倍数 计算顺序不能换
ll LCM(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void Solve() {
    cout << LCM(40, 20) << endl;
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
