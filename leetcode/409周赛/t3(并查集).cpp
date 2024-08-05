#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 并查集好题

class Solution {
public:
    struct DSU {
        vector<int> father;
        int set;

        // 初始化
        DSU(int n) : father(n + 2, 0), set(n - 1) {
            for (int i = 0; i <= n; i++)
                father[i] = i;
        }

        // 递归调用版本find
        int find(int i) {
            if (i != father[i])
                father[i] = find(father[i]);
            return father[i];
        }

        // 判断是不是同一个老大
        bool isSameSet(int x, int y) {
            return find(x) == find(y);
        }

        // 合并x跟y
        void unionSets(int x, int y) {
            int fx = find(x), fy = find(y);
            if (fx != fy) {
                father[fx] = fy;
                set--;
            }
        }
    };

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &ql) {
        DSU ui(n);
        vector<int> ans;

        for (auto q : ql) {
            // l-r是边的编号，合并l到r-1的全部边
            int l = q[0], r = q[1] - 1;
            int fr = ui.find(r);
            // 优化，== for (int i = l; i < r; i = i++)
            for (int i = ui.find(l); i < r; i = ui.find(i + 1)) {
                ui.unionSets(i, fr);
            }
            ans.push_back(ui.set);
        }

        return ans;
    }
};

void Solve() {
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
