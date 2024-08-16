#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

struct DSU {
    vector<int> father;
    int set;

    // ��ʼ��
    DSU(int n) : father(n + 2, 0), set(n) {
        for (int i = 0; i <= n; i++)
            father[i] = i;
    }

    // �ݹ���ð汾find
    int find(int i) {
        if (i != father[i])
            father[i] = find(father[i]);
        return father[i];
    }

    // �ж��ǲ���ͬһ���ϴ�
    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }

    // �ϲ�x��y
    void unionSets(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy)
            father[fx] = fy;
    }
};

void issue() {
    int n, m;
    cin >> n >> m;
    // ���ã�����һ����С��n������
    DSU ui(n);
    while (m--) {
        int a, x, y;
        cin >> a >> x >> y;
        if (a == 2) {
            if (ui.isSameSet(x, y))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        } else
            ui.unionSets(x, y);
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
        issue();
    }
    return 0;
}
