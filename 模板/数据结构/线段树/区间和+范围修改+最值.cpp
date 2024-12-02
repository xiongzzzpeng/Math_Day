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
绾挎�垫爲
寤烘爲鐨勮繃绋嬫槸O(n)
鍗曟�℃煡璇㈢殑鏃堕棿澶嶆潅搴�O(logn)
鍖洪棿淇�鏀筄(logn)
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

    // 鏌ヨ�㈠尯闂� [x, y)锛岃兘杩斿洖鍖洪棿鏈€澶у€硷紝鍖洪棿鏈€澶у€煎嚭鐜版�℃暟
    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }

    // [x, y)鐨勫尯闂村拰
    i64 Sum(int x, int y) {
        return query(1, 0, n, x, y).sum;
    }

    // 灏� [x, y) 鍖洪棿鍐呮坊鍔� v
    void rangeAdd(int x, int y, int v) {
        rangeAdd(1, 0, n, x, y, v);
    }

    // 灏� x 澶勭殑鍊兼敼涓� v
    void modify(int x, const Info &v) {
        modify(1, 0, n, x, v);
    }

   private:
    int n;              // 鍘熸暟缁勭殑澶у皬
    vector<int> tag;    // 鎳掓儼鏍囪�帮紝鐢ㄤ簬鍖洪棿鏇存柊
    vector<Info> info;  // 绾挎�垫爲鑺傜偣锛屽寘鍚�鍖洪棿鐨勪俊鎭�

    // 浠庡瓙鑺傜偣鏇存柊褰撳墠鑺傜偣鐨勪俊鎭�
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    // 灏嗗€� v 娣诲姞鍒板綋鍓嶈妭鐐癸紙鐢ㄤ簬鎳掓儼浼犳挱锛�
    void add(int p, int v, int l, int r) {
        tag[p] += v;
        info[p].max += v;
        info[p].sum += v * (r - l);
    }

    // 灏嗘噿鎯版爣璁板悜瀛愯妭鐐逛紶閫�
    void push(int p, int l, int r) {
        int m = (l + r) / 2;
        add(2 * p, tag[p], l, m);
        add(2 * p + 1, tag[p], m, r);
        tag[p] = 0;
    }

    // 鍐呴儴鏌ヨ�㈠嚱鏁帮紝鐢ㄤ簬鑾峰彇鍖洪棿 [x, y) 鐨勪俊鎭�
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return {};  // 濡傛灉瓒呭嚭鏌ヨ�㈣寖鍥达紝杩斿洖绌虹殑 Info 瀵硅薄
        }
        if (l >= x && r <= y) {
            return info[p];  // 瀹屽叏鍦ㄦ煡璇㈣寖鍥村唴
        }
        int m = (l + r) / 2;
        push(p, l, r);  // 鍚戜笅浼犻€掓噿鎯版爣璁帮紝纭�淇濇墍鏈夋洿鏂板凡搴旂敤
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);  // 鍚堝苟宸﹀彸瀛愯妭鐐圭殑缁撴灉
    }

    // 鍐呴儴鍑芥暟锛屽皢鍊� v 娣诲姞鍒板尯闂� [x, y) 鐨勬墍鏈夊厓绱犱腑
    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) {
            return;  // 瓒呭嚭鑼冨洿
        }
        if (l >= x && r <= y) {
            add(p, v, l, r);  // 瀹屽叏鍦ㄨ寖鍥村唴锛岀洿鎺ユ坊鍔犲€�
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);  // 鍚戜笅浼犻€掓噿鎯版爣璁帮紝纭�淇濇墍鏈夋洿鏂板凡搴旂敤
        rangeAdd(2 * p, l, m, x, y, v);      // 瀵瑰乏瀛愯妭鐐瑰簲鐢ㄥ尯闂村姞娉�
        rangeAdd(2 * p + 1, m, r, x, y, v);  // 瀵瑰彸瀛愯妭鐐瑰簲鐢ㄥ尯闂村姞娉�
        pull(p);                             // 浠庡瓙鑺傜偣鏇存柊褰撳墠鑺傜偣鐨勪俊鎭�
    }

    // 鍐呴儴鍑芥暟锛屼慨鏀圭储寮� x 澶勭殑鍏冪礌涓哄€� v
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;  // 鍙跺瓙鑺傜偣锛岀洿鎺ヤ慨鏀�
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);  // 鍚戜笅浼犻€掓噿鎯版爣璁帮紝纭�淇濇墍鏈夋洿鏂板凡搴旂敤
        if (x < m) {
            modify(2 * p, l, m, x, v);  // 鍦ㄥ乏瀛愯妭鐐逛腑淇�鏀�
        } else {
            modify(2 * p + 1, m, r, x, v);  // 鍦ㄥ彸瀛愯妭鐐逛腑淇�鏀�
        }
        pull(p);  // 浠庡瓙鑺傜偣鏇存柊褰撳墠鑺傜偣鐨勪俊鎭�
    }
};

void Solve() {
    int n = 10;
    SegmentTree segTree(n);

    // 鍒濆�嬪寲绾挎�垫爲
    for (int i = 0; i < n; i++) {
        // 绗�涓変釜浣嶇疆鏀惧～鍏ョ殑鍊�
        segTree.modify(i, {i, 1, i});
    }

    // 鏌ヨ�㈠尯闂� [0, 5) 鐨勬渶澶у€煎拰鏈€澶у€煎嚭鐜版�℃暟
    Info result = segTree.query(0, 5);
    cout << result.max << result.cnt << endl;

    // 鏌ヨ�㈠尯闂� [0, 5) 鐨勭疮鍔犲拰
    int sumResult = segTree.Sum(0, 5);
    cout << sumResult << endl;

    // 灏嗗尯闂� [2, 7) 鍐呯殑鎵€鏈夊厓绱犲姞 3
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
