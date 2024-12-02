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

/*
�߶���
�����Ĺ�����O(n)
���β�ѯ��ʱ�临�Ӷ�O(logn)
�����޸�O(logn)
*/

class SegmentTree {
   public:
    // ���±�1��ʼ
    SegmentTree(vector<int>& inputArr) {
        int n = inputArr.size();
        arr = inputArr;
        sum.resize(4 * n);
        nums.resize(4 * n, 0);
        build(1, n, 1);
    }

    // [l, r]�ϵ�ֵ����val, n������Ĵ�С
    void addRange(int l, int r, i64 val, int n) {
        add(l, r, val, 1, n, 1);
    }

    // [l, r]�ϵĺ�, n�������С
    i64 sumRange(int l, int r, int n) {
        return query(l, r, 1, n, 1);
    }

   private:
    vector<int> arr;   // ԭʼ��������
    vector<i64> sum;   // �߶����ڵ�洢�����
    vector<i64> nums;  // �洢��������Ϣ

    // ���¸��ڵ�
    void up(int i) {
        sum[i] = sum[i * 2] + sum[i * 2 + 1];
    }

    // �·���������Ϣ
    void down(int i, int ln, int rn) {
        if (nums[i] != 0) {
            // ����������Ϣ���ݸ������ӽڵ�
            lazy(i * 2, nums[i], ln);
            lazy(i * 2 + 1, nums[i], rn);
            nums[i] = 0;  // �����ǰ�ڵ�������±��
        }
    }

    // �Ե�ǰ������������
    void lazy(int i, i64 v, int n) {
        sum[i] += v * n;
        nums[i] += v;
    }

    // �����߶���
    void build(int l, int r, int i) {
        if (l == r) {
            sum[i] = arr[l - 1];  // ���������������1-based������������Ҫ����Ϊ arr[l-1]
        } else {
            int mid = (l + r) / 2;
            build(l, mid, i * 2);          // ������
            build(mid + 1, r, i * 2 + 1);  // ������
            up(i);                         // ���µ�ǰ�ڵ�
        }
        nums[i] = 0;  // ��ʼ������������
    }

    // �������Ӳ���
    void add(int jobl, int jobr, i64 jobv, int l, int r, int i) {
        if (jobl <= l && r <= jobr) {
            lazy(i, jobv, r - l + 1);
        } else {
            int mid = (l + r) / 2;
            down(i, mid - l + 1, r - mid);
            if (jobl <= mid) {
                add(jobl, jobr, jobv, l, mid, i * 2);
            }
            if (jobr > mid) {
                add(jobl, jobr, jobv, mid + 1, r, i * 2 + 1);
            }
            up(i);
        }
    }

    // �����ѯ����
    i64 query(int jobl, int jobr, int l, int r, int i) {
        if (jobl <= l && r <= jobr) {
            return sum[i];
        }
        int mid = (l + r) / 2;
        down(i, mid - l + 1, r - mid);
        i64 ans = 0;
        if (jobl <= mid) {
            ans += query(jobl, jobr, l, mid, i * 2);
        }
        if (jobr > mid) {
            ans += query(jobl, jobr, mid + 1, r, i * 2 + 1);
        }
        return ans;
    }
};

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegmentTree seg(a);

    while (m--) {
        int op, l, r;
        i64 val;
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> val;
            seg.addRange(l, r, val, n);
        } else {
            cin >> l >> r;
            cout << seg.sumRange(l, r, n) << "\n";
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
