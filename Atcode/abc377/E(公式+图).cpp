#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

// p[i] -> p[p[i]] 就是p(2 ^ k)[i]
// 就是 位置1连接a[1] 2连接a[2]..的图 变成k是沿边走p(2 ^ k)次

i64 qpow(i64 a, i64 b, int mod) {
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

void Solve() {
    int n;
    i64 k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }

        int j = i;
        vector<int> a;
        while (!vis[j]) {
            vis[j] = true;
            a.push_back(j);
            j = p[j];
        }

        i64 d = qpow(2, k, a.size());
        for (int x = 0; x < a.size(); x++) {
            p[a[x]] = a[(x + d) % a.size()];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " \n"[i == n - 1];
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
