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

// AC自动机
// 大文章中找一些匹配的字符串,也可以有命中几次

// 模板，不能修改！！！
const int maxn = 200051;

int n, cnt, vis[200051], ans, in[maxn], Map[maxn];
struct kkk {
    int son[26], fail, flag, ans;
    void clear() {
        memset(son, 0, sizeof(son)), fail = flag = ans = 0;
    }
} trie[maxn];
queue<int> q;
void insert(string& s, int num) {
    int u = 1, len = s.size();
    for (int i = 0; i < len; i++) {
        int v = s[i] - 'a';
        if (!trie[u].son[v]) trie[u].son[v] = ++cnt;
        u = trie[u].son[v];
    }
    if (!trie[u].flag) trie[u].flag = num;
    Map[num] = trie[u].flag;
}
void getFail() {
    for (int i = 0; i < 26; i++) trie[0].son[i] = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int Fail = trie[u].fail;
        for (int i = 0; i < 26; i++) {
            int v = trie[u].son[i];
            if (!v) {
                trie[u].son[i] = trie[Fail].son[i];
                continue;
            }
            trie[v].fail = trie[Fail].son[i];
            in[trie[v].fail]++;
            q.push(v);
        }
    }
}
void topu() {
    for (int i = 1; i <= cnt; i++)
        if (in[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[trie[u].flag] = trie[u].ans;
        int v = trie[u].fail;
        in[v]--;
        trie[v].ans += trie[u].ans;
        if (in[v] == 0) q.push(v);
    }
}
void query(string& s) {
    int u = 1, len = s.size();
    for (int i = 0; i < len; i++) u = trie[u].son[s[i] - 'a'], trie[u].ans++;
}
// ！！！

void Solve() {
    int n;
    cin >> n;

    string s, T;
    cnt = 1;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        insert(s, i);
    }
    cin >> T;

    getFail();
    query(T);
    topu();

    for (int i = 1; i <= n; i++) {
        cout << vis[Map[i]] << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

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