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

struct Info {
    int max = -1E9;
    int cnt = 0;
    i64 sum = 0;
};

Info operator+(const Info &a, const Info &b) {
    Info res;
    if (a.max > b.max) {
        res.max = a.max;
        res.cnt = a.cnt;
    } else if (a.max < b.max) {
        res.max = b.max;
        res.cnt = b.cnt;
    } else {
        res.max = a.max;
        res.cnt = a.cnt + b.cnt;
    }
    res.sum = a.sum + b.sum;
    return res;
}

class SegmentTree {
   public:
    SegmentTree(int n_) : n(n_), tag(4 * n), info(4 * n) {}

    // ��ѯ���� [x, y)���ܷ����������ֵ���������ֵ���ִ���
    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }

    // [x, y)�������
    i64 Sum(int x, int y) {
        return query(1, 0, n, x, y).sum;
    }

    // �� [x, y) ��������� v
    void rangeAdd(int x, int y, int v) {
        rangeAdd(1, 0, n, x, y, v);
    }

    // �� x ����ֵ��Ϊ v
    void modify(int x, const Info &v) {
        modify(1, 0, n, x, v);
    }

   private:
    int n;              // ԭ����Ĵ�С
    vector<int> tag;    // �����ǣ������������
    vector<Info> info;  // �߶����ڵ㣬�����������Ϣ

    // ���ӽڵ���µ�ǰ�ڵ����Ϣ
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    // ��ֵ v ��ӵ���ǰ�ڵ㣨�������贫����
    void add(int p, int v, int l, int r) {
        tag[p] += v;
        info[p].max += v;
        info[p].sum += v * (r - l);
    }

    // �����������ӽڵ㴫��
    void push(int p, int l, int r) {
        int m = (l + r) / 2;
        add(2 * p, tag[p], l, m);
        add(2 * p + 1, tag[p], m, r);
        tag[p] = 0;
    }

    // �ڲ���ѯ���������ڻ�ȡ���� [x, y) ����Ϣ
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return {};  // ���������ѯ��Χ�����ؿյ� Info ����
        }
        if (l >= x && r <= y) {
            return info[p];  // ��ȫ�ڲ�ѯ��Χ��
        }
        int m = (l + r) / 2;
        push(p, l, r);  // ���´��������ǣ�ȷ�����и�����Ӧ��
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);  // �ϲ������ӽڵ�Ľ��
    }

    // �ڲ���������ֵ v ��ӵ����� [x, y) ������Ԫ����
    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) {
            return;  // ������Χ
        }
        if (l >= x && r <= y) {
            add(p, v, l, r);  // ��ȫ�ڷ�Χ�ڣ�ֱ�����ֵ
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);                       // ���´��������ǣ�ȷ�����и�����Ӧ��
        rangeAdd(2 * p, l, m, x, y, v);      // �����ӽڵ�Ӧ������ӷ�
        rangeAdd(2 * p + 1, m, r, x, y, v);  // �����ӽڵ�Ӧ������ӷ�
        pull(p);                             // ���ӽڵ���µ�ǰ�ڵ����Ϣ
    }

    // �ڲ��������޸����� x ����Ԫ��Ϊֵ v
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;  // Ҷ�ӽڵ㣬ֱ���޸�
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);  // ���´��������ǣ�ȷ�����и�����Ӧ��
        if (x < m) {
            modify(2 * p, l, m, x, v);  // �����ӽڵ����޸�
        } else {
            modify(2 * p + 1, m, r, x, v);  // �����ӽڵ����޸�
        }
        pull(p);  // ���ӽڵ���µ�ǰ�ڵ����Ϣ
    }
};

void Solve() {
    int n = 10;
    SegmentTree segTree(n);

    // ��ʼ���߶���
    for (int i = 0; i < n; i++) {
        // ������λ�÷������ֵ
        segTree.modify(i, {i, 1, i});
    }

    // ��ѯ���� [0, 5) �����ֵ�����ֵ���ִ���
    Info result = segTree.query(0, 5);
    cout << result.max << result.cnt << endl;

    // ��ѯ���� [0, 5) ���ۼӺ�
    int sumResult = segTree.Sum(0, 5);
    cout << sumResult << endl;

    // ������ [2, 7) �ڵ�����Ԫ�ؼ� 3
    segTree.rangeAdd(2, 7, 3);
    cout << segTree.Sum(2, 7) << "\n";

    segTree.rangeAdd(0, 2, 2);
    cout << segTree.Sum(0, 2) << "\n";
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
