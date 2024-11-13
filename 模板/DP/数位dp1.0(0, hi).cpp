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

class Solution {
   public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int m = s.size();

        vector<vector<int>> mem(m, vector<int>(1 << 10, -1));

        // is_limit:�����ޣ���ö�ٵ�s[i]�ͻ�Ӱ�쵽���������
        // is_num:ǰ���Ƿ������������Ϳ�����0-9֮��ѡ������ǰ0���Ϸ�
        auto dfs = [&](auto &self, int i, int mask, bool is_limit, bool is_num) -> int {
            if (i == m) {
                return is_num;
            }
            if (!is_limit && is_num && mem[i][mask] != -1) {
                return mem[i][mask];
            }
            int res = 0;
            // ǰ��û�����Ҳ����
            if (!is_num) {
                res = self(self, i + 1, mask, false, false);
            }

            int up = is_limit ? s[i] - '0' : 9;
            for (int d = is_num ? 0 : 1; d <= up; d++) {
                if ((mask >> d & 1) == 0) {
                    res += self(self, i + 1, mask | (1 << d), is_limit && d == up, true);
                }
            }
            if (!is_limit && is_num) {
                mem[i][mask] = res;
            }
            return res;
        };

        // һ��ʼҪ�յ����ƺͲ�����0
        return dfs(dfs, 0, 0, true, false);
    }
};

void Solve() {}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}