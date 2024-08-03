#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 从下标一开始的

struct Differe {
    const int MAXN = 1002;
    int n, q;
    vector<int> diff_1;
    vector<vector<int>> diff_2;

    // 初始化一维差分
    Differe(int n) : n(n) {
        diff_1.resize(MAXN, 0);
    }
    // 初始化二维差分
    Differe(int n, int q) : n(n), q(q) {
        diff_2.resize(MAXN, vector<int>(MAXN, 0));
    }

    // 添加一维差分
    void add_1(int l, int r, int k) {
        diff_1[l] += k;
        diff_1[r + 1] = -k;
    }
    // 添加二维差分
    void add_2(int a, int b, int c, int d, int k) {
        diff_2[a][b] += k;
        diff_2[c + 1][b] -= k;
        diff_2[a][d + 1] -= k;
        diff_2[c + 1][d + 1] += k;
    }

    // 还原一维差分
    void build_1() {
        for (int i = 1; i < MAXN; i++) {
            diff_1[i] += diff_1[i - 1];
        }
    }

    // 还原二维差分
    void build_2() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                diff_2[i][j] += diff_2[i - 1][j] + diff_2[i][j - 1] - diff_2[i - 1][j - 1];
            }
        }
    }
};

void Solve() {
    vector<int> test = {0, 1, 1, 1, 1, 1};
    int n, q;
    cin >> n >> q;
    Differe differe_1(n);
    differe_1.add_1(1, 3, 2);
    differe_1.build_1();
    for (int i = 1; i <= n; i++)
        cout << test[i] + differe_1.diff_1[i] << " ";
    cout << endl;

    Differe differe(n, q);
    for (int i = 1, a, b, c, d; i <= q; i++) {
        cin >> a >> b >> c >> d;
        differe.add_2(a, b, c, d, 1);
    }
    differe.build_2();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << differe.diff_2[i][j] << " ";
        }
        cout << endl;
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
