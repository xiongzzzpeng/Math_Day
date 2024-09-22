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

// �η����Ի��ɽ��������ǣ���2^n ���Ƕ�����

void Solve() {
    int M;
    cin >> M;

    vector<int> cnt;  // ��¼���ֵĴ���
    for (int i = 1; i <= M; i *= 3) {
        // �����Ʒ��� i *= 2 M / i % 2
        cnt.push_back(M / i % 3);  // ת�����Ƶķ��� �����3����
    }

    vector<int> ans;
    for (int i = 0; i < cnt.size(); i++) {
        while (cnt[i]--) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (auto v : ans) {
        cout << v << " ";
    }
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
