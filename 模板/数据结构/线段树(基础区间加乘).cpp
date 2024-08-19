#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// �߶�����������ϲ�������
// ʱ�临�Ӷ�: ��Χ�޸ģ���Χ��ѯ log^n
// ���÷�Χ: �����ڵ� ���ֵ ��Сֵ �ۼӺ�(����ά�����ֵ������)

struct SegmentTree {
    const ll P = 1e12 + 7;
    int n;
    std::vector<ll> tag, sum, addTag;

    SegmentTree(int n_) : n(n_), tag(4 * n, 1), sum(4 * n), addTag(4 * n, 0) {}

    void pull(int p) {
        sum[p] = (sum[2 * p] + sum[2 * p + 1]) % P;
    }

    void applyMul(int p, ll v) {
        tag[p] = tag[p] * v % P;
        sum[p] = sum[p] * v % P;
        addTag[p] = addTag[p] * v % P;
    }

    void applyAdd(int p, ll v, int len) {
        sum[p] = (sum[p] + v * len % P) % P;
        addTag[p] = (addTag[p] + v) % P;
    }

    void push(int p, int l, int r) {
        int m = (l + r) / 2;
        applyMul(2 * p, tag[p]);
        applyMul(2 * p + 1, tag[p]);
        applyAdd(2 * p, addTag[p], m - l);
        applyAdd(2 * p + 1, addTag[p], r - m);
        tag[p] = 1;
        addTag[p] = 0;
    }

    // ��ѯ[l, r)�ĺ�
    ll query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return 0;
        }
        if (l >= x && r <= y) {
            return sum[p];
        }
        int m = (l + r) / 2;
        push(p, l, r);
        return (query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y)) % P;
    }

    ll query(int x, int y) {
        return query(1, 0, n, x, y);
    }

    // [l, r)�ϳ�v
    void rangeMul(int p, int l, int r, int x, int y, ll v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            return applyMul(p, v);
        }
        int m = (l + r) / 2;
        push(p, l, r);
        rangeMul(2 * p, l, m, x, y, v);
        rangeMul(2 * p + 1, m, r, x, y, v);
        pull(p);
    }

    void rangeMul(int x, int y, ll v) {
        rangeMul(1, 0, n, x, y, v);
    }

    // [l, r)�ϼ�v
    void rangeAdd(int p, int l, int r, int x, int y, ll v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            return applyAdd(p, v, r - l);
        }
        int m = (l + r) / 2;
        push(p, l, r);
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        pull(p);
    }

    void rangeAdd(int x, int y, ll v) {
        rangeAdd(1, 0, n, x, y, v);
    }

    void add(int p, int l, int r, int x, ll v) {
        if (r - l == 1) {
            sum[p] = (sum[p] + v) % P;
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);
        if (x < m) {
            add(2 * p, l, m, x, v);
        } else {
            add(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }

    // ��x�����v
    void add(int x, ll v) {
        add(1, 0, n, x, v);
    }
};

void Solve() {
    int n = 5;
    SegmentTree segTree(n);

    // ���ֵ���߶���
    segTree.add(0, 5); // ������0���5
    segTree.add(1, 3); // ������1���3
    segTree.add(2, 7); // ������2���7
    segTree.add(3, 9); // ������3���9
    segTree.add(4, 6); // ������4���6

    // �Է�Χ[1, 4)ÿ��Ԫ�ؼ�2
    segTree.rangeAdd(1, 4, 2);

    // ��ѯ��Χ[1, 4)�ĺ� = 25
    cout << segTree.query(1, 4) << endl;

    // �Է�Χ[1, 4)ÿ��Ԫ�س�2
    segTree.rangeMul(1, 4, 2);

    // ��ѯ��Χ[1, 4)�ĺ� = 50
    cout << segTree.query(1, 4) << endl;
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
