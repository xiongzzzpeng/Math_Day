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

// 逆序对基本思想：离散化 + 从后往前遍历 + Fenwick

template <typename T>
class Fenwick {
   public:
    Fenwick(int n_ = 0) {
        init(n_);
    }

    // 在i的位置添加val
    void add(int i, const T& val) {
        for (; i <= n; i += i & -i) {
            a[i] += val;
        }
    }

    // 求sum([1, i])
    T sum(int i) {
        T ans{};
        for (; i > 0; i -= i & -i) {
            ans += a[i];
        }
        return ans;
    }

    // 求sum([r, l])
    T rangeSum(int left, int right) {
        return sum(right) - sum(left - 1);
    }

    // 找 <= k的最大下标
    int select(const T& k) {
        int res = 0;
        T cur{};
        for (int i = 1 << __lg(n); i; i /= 2) {
            if (res + i <= n && cur + a[res + i] <= k) {
                res += i;
                cur += a[res];
            }
        }
        return res;
    }

   private:
    int n;
    vector<T> a;

    void init(int n_) {
        n = n_;
        a.assign(n + 2, T{});
    }
};

// 离散化，原数组的每一个元素在副本中的位置，位置即为排名，将其作为离散化后的值。
// [0 , n - 1]
vector<int> LSH(vector<int>& arr) {
    vector<int> tmp(arr);

    sort(tmp.begin(), tmp.end());

    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
    }
    return arr;
}

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a = LSH(a);

    i64 ans = 0;
    Fenwick<i64> fenwick(n);
    for (int i = n - 1; i >= 0; i--) {
        ans += fenwick.sum(a[i]);
        fenwick.add(a[i] + 1, 1);
    }
    cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen("zcy.in", "r", stdin);
    freopen("zcy.out", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
