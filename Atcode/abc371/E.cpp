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

// ��������Ǽ������һ��������������Ĺ���
// [x, p] p�����ڵ�λ�ã�����֮������䶼û��

void Solve() {
    i64 N;
    cin >> N;

    vector<vector<int>> lst(N);
    for (int i = 0; i < N; i++) {
        lst[i].push_back(-1);  // ��ʼ-1
    }
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        lst[A - 1].push_back(i);
    }
    for (int i = 0; i < N; i++) {
        lst[i].push_back(N);  // �������
    }

    i64 ans = 0;
    for (int i = 0; i < N; i++) {
        ans += N * (N + 1) / 2;  // �������еĴ���
        for (int j = 1; j < (int)lst[i].size(); j++) {
            i64 tmp = (lst[i][j] - lst[i][j - 1] - 1);  // ��¼λ�ó���, [2, 3]����0
            ans -= tmp * (tmp + 1) / 2;
        }
    }

    cout << ans << endl;
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
