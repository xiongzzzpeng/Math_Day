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

// ��״���飨O(logn)��
// һ����1�±꿪ʼ ��Χ�� [lowbit(x) + 1, x]
// �� 2 0010 ȡ����ߵ�1 0000 �ټ�1 [0001, 2]
// add: i += ���Ҳ�1 3: 0011 + 0001 = 4 4: 0100 + 0100 = 8
// sum: i -= ���Ҳ�1 3��0011 - 0001 = 2 2�� 0010 - 0010 = 0
// �������Ӻͷ�Χ��ѯ���ɲ����Ϣ��

template <typename T>
class Fenwick {
   public:
    Fenwick(int n_ = 0) {
        init(n_);
    }

    // ��i��λ�����val
    void add(int i, const T& val) {
        for (; i <= n; i += i & -i) {
            a[i] += val;
        }
    }

    // ��sum([1, i])
    T sum(int i) {
        T ans{};
        for (; i > 0; i -= i & -i) {
            ans += a[i];
        }
        return ans;
    }

    // ��sum([r, l])
    T rangeSum(int left, int right) {
        return sum(right) - sum(left - 1);
    }

    // �� <= k������±�
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

// �������ӣ���Ĳ�ѯ
// ��Fenwickά��������飬sum([1, i])�͵��ֵ
void diff() {
    int n, m;
    cin >> n >> m;

    Fenwick<int> fenwick(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        fenwick.add(i, x);
        fenwick.add(i + 1, -x);
    }
    while (m--) {
        int a;
        cin >> a;
        if (a == 1) {
            int left, right, val;
            cin >> left >> right >> val;
            fenwick.add(left, val);
            fenwick.add(right + 1, -val);
        } else {
            int b;
            cin >> b;
            cout << fenwick.sum(b) << "\n";
        }
    }
}

void Solve() {
    int n, m;
    cin >> n >> m;

    Fenwick<int> fenwick(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        fenwick.add(i, x);
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            fenwick.add(b, c);
        }
        if (a == 2) {
            cout << fenwick.rangeSum(b, c) << "\n";
        }
    }
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
