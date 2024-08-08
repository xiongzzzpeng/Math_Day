#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469

ll merge(int l, int m, int r, vector<int> &num) {
    ll ans = 0;
    int i = l, j = m + 1, sum = 0;
    while (j <= r) {
        while (i <= m && num[i] <= num[j]) {
            sum += num[i++];
        }
        ans += sum;
        j++;
    }

    // ¹é²¢ÅÅÐòÄ£°å
    int a = l;
    int b = m + 1;
    vector<int> temp(r - l + 1);
    int index = 0;
    while (a <= m && b <= r) {
        if (num[a] <= num[b]) {
            temp[index++] = num[a++];
        } else {
            temp[index++] = num[b++];
        }
    }
    while (a <= m) {
        temp[index++] = num[a++];
    }
    while (b <= r) {
        temp[index++] = num[b++];
    }
    for (int i = 0; i < temp.size(); i++) {
        num[l + i] = temp[i];
    }

    return ans;
}

ll sum(int l, int r, vector<int> &num) {
    if (l == r)
        return 0;
    int m = (l + r) / 2;
    return sum(l, m, num) + sum(m + 1, r, num) + merge(l, m, r, num);
}

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << sum(0, n - 1, a) << endl;
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
