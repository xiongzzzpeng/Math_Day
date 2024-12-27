#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

vector<int> LSH(vector<int> &arr) {
    vector<int> tmp(arr);

    sort(tmp.begin(), tmp.end());

    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    // for (int i = 0; i < arr.size(); i++) {
    //     arr[i] = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
    // }
    return tmp;
}

void Solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    vector<int> dct;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dct.push_back(a[i]);
        dct.push_back(a[i] + 1);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        dct.push_back(b[i]);
        dct.push_back(b[i] + 1);
    }

    dct = LSH(dct);

    auto find = [&](int x) { return lower_bound(dct.begin(), dct.end(), x) - dct.begin(); };

    vector<int> bdr(dct.size() + 1), consumer(dct.size() + 1);
    for (int i = 0; i < n; i++) {
        bdr[find(a[i] + 1)]++, bdr[find(b[i] + 1)]--;
        consumer[find(b[i])]++;
    }
    for (int i = 1; i < dct.size(); i++) {
        bdr[i] += bdr[i - 1];
    }
    for (int i = dct.size() - 2; i >= 0; i--) {
        consumer[i] += consumer[i + 1];
    }

    i64 ans = 0;
    for (int i = 0; i < dct.size(); i++) {
        if (bdr[i] <= k) {
            ans = max(ans, 1LL * consumer[i] * dct[i]);
        }
    }
    cout << ans << "\n";
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
