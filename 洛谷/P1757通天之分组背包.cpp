#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 分组背包问题

void Solve2() {
    int n, m;
    cin >> m >> n;

    vector<vector<int>> arr(n + 1, vector<int>(3));
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    sort(arr.begin() + 1, arr.begin() + 1 + n, [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; });

    int teams = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[i][2] != arr[i - 1][2])
            teams++;
    }

    vector<int> dp(m + 1);
    for (int i = 1, l = 1, r = 2; l <= n; i++) {
        while (r <= n && arr[l][2] == arr[r][2]) {
            r++;
        }

        for (int j = m; j >= 0; j--) {
            for (int k = l; k < r; k++) {
                if (j - arr[k][0] >= 0) {
                    dp[j] = max(dp[j], arr[k][1] + dp[j - arr[k][0]]);
                }
            }
        }
        l = r++;
    }
    cout << dp[m] << endl;
}

void Solve() {
    int n, m;
    cin >> m >> n;

    vector<vector<int>> arr(n + 1, vector<int>(3));
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    sort(arr.begin() + 1, arr.begin() + 1 + n, [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; });

    int teams = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[i][2] != arr[i - 1][2])
            teams++;
    }

    vector<vector<int>> dp(teams + 1, vector<int>(m + 1));
    for (int i = 1, l = 1, r = 2; l <= n; i++) {
        // l和r是记录该组的多少
        while (r <= n && arr[r][2] == arr[l][2]) {
            r++;
        }
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = l; k < r; k++) {
                if (j >= arr[k][0]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[k][0]] + arr[k][1]);
                }
            }
        }
        l = r++;
    }

    cout << dp[teams][m] << endl;
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
        Solve2();
    }
    return 0;
}
