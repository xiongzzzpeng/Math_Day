#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

void Solve() {
    string S, T;
    cin >> S >> T;

    // ��Ϊ�ֵ���,�����ȰѴ�ĸ�С,��ǰ����
    vector<string> ans;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] > T[i]) {
            S[i] = T[i];
            ans.push_back(S);
        }
    }
    // �ٴӺ���ǰ�Ĵ�
    for (int i = S.size() - 1; i >= 0; i--) {
        if (S[i] < T[i]) {
            S[i] = T[i];
            ans.push_back(S);
        }
    }

    cout << ans.size() << endl;
    for (auto &c : ans) {
        cout << c << endl;
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
