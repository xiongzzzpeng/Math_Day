#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 二分答案法
// 在[b - d, b + d]区间内k[i]个数
// 求mid(d)

void Solve() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N), B(Q), K(Q);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < Q; i++)
        cin >> B[i] >> K[i];

    sort(A.begin(), A.end());

    for (int i = 0; i < Q; i++) {
        int lb = 0, rb = 2e8;
        while (lb < rb) {
            int mid = lb + ((rb - lb) >> 1);

            int l = B[i] - mid;
            int r = B[i] + mid;

            int cnt = upper_bound(A.begin(), A.end(), r) - lower_bound(A.begin(), A.end(), l);
            if (cnt >= K[i])
                rb = mid;
            else
                lb = mid + 1;
        }
        cout << rb << endl;
    }
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
