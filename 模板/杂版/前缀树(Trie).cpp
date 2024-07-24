#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

struct TrieTree {
    const int MAXN = 150001;
    vector<vector<int>> tree;
    vector<int> pass;
    vector<int> end;
    int cnt;

    TrieTree() {
        tree.resize(MAXN, vector<int>(26, 0));
        pass.resize(MAXN, 0);
        end.resize(MAXN, 0);
        cnt = 1;
    }

    void build() {
        cnt = 1;
    }

    void insert(string &s) {
        // 头节点
        int cur = 1;
        pass[cur]++;
        for (int i = 0, path; i < s.size(); i++) {
            path = s[i] - 'a';
            if (tree[cur][path] == 0)
                tree[cur][path] = ++cnt;
            cur = tree[cur][path];
            pass[cur]++;
        }
        end[cur]++;
    }

    // 找整个结尾的
    int search(string &s) {
        int cur = 1;
        for (int i = 0, path; i < s.size(); i++) {
            path = s[i] - 'a';
            if (tree[cur][path] == 0)
                return 0;
            cur = tree[cur][path];
        }
        return end[cur];
    }

    // 找前缀
    int pre(string &s) {
        int cur = 1;
        for (int i = 0, path; i < s.size(); i++) {
            path = s[i] - 'a';
            if (!tree[cur][path])
                return 0;
            cur = tree[cur][path];
        }
        return pass[cur];
    }

    void deleteWord(string &s) {
        if (search(s) > 0) {
            int cur = 1;
            for (int i = 0, path; i < s.length(); i++) {
                path = s[i] - 'a';
                if (--pass[tree[cur][path]] == 0) {
                    tree[cur][path] = 0;
                    return;
                }
                cur = tree[cur][path];
            }
            end[cur]--;
        }
    }

    void clear() {
        for (int i = 1; i <= cnt; i++) {
            fill(tree[i].begin(), tree[i].end(), 0);
            end[i] = 0;
            pass[i] = 0;
        }
    }
};

void Solve() {
    TrieTree trie;
    trie.build();
    int n, m;
    cin >> m;

    while (m--) {
        cin >> n;
        if (n == 1) {
            string s;
            cin >> s;
            trie.insert(s);
        } else if (n == 2) {
            string s;
            cin >> s;
            trie.deleteWord(s);
        } else if (n == 3) {
            string s;
            cin >> s;
            cout << (trie.search(s) > 0 ? "YES" : "NO") << endl;
        } else if (n == 4) {
            string s;
            cin >> s;
            cout << trie.pre(s) << endl;
        }
    }
    trie.clear();
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
