#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void Solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i];
    }

    vector<array<int, 2>> seq;
    seq.push_back({m, m});

    bool flag = false;
    vector<int> ans;
    for (int x : a) {
        bool tmp = false;
        for (int i = seq.size() - 1; i >= 0; i--) {
            if (seq[i][0] <= x && x <= seq[i][1]) {
                if (x == seq[i][0] && x == seq[i][1] && x != 1 && x != n) seq.erase(seq.begin() + i);
                tmp = true;
            } else if (x < seq[i][0])
                seq[i][0]--;
            else if (x > seq[i][1])
                seq[i][1]++;
        }
        if (tmp && !flag) {
            flag = true;
            bool before = false, now = false;
            for (int i = 0; i < seq.size(); i++) {
                if (seq[i][0] <= 1 && 1 <= seq[i][1]) before = true;
                if (seq[i][0] <= n && n <= seq[i][1]) now = true;
            }
            if (!before) {
                seq.push_back({1, 1});
            }
            if (!now) {
                seq.push_back({n, n});
            }
        }

        sort(seq.begin(), seq.end());

        int res = 0;
        int cnt = 0;
        for (auto [l, r] : seq) {
            int lo = max(1, l);
            int hi = min(n, r);
            lo = max(lo, cnt + 1);
            if (lo <= hi) res += hi - lo + 1;
            cnt = max(cnt, hi);
        }
        ans.push_back(res);
    }

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
