#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

struct KMP {
    string tmp; // Ŀ�괮
    vector<int> next;

    KMP(const string &pat) : tmp(pat), next(md_next(pat)) {}

    // ���ı�������Ŀ�괮�Ŀ�ͷλ�ã�����¼���з���������λ��
    vector<int> strStr(const string &text) {
        int n = text.size(), m = tmp.size();
        int x = 0; // �ı����еĵ�ǰλ��
        int y = 0; // Ŀ�괮�еĵ�ǰλ��

        vector<int> matches; // ��¼����ƥ��λ��

        while (x < n) {
            if (text[x] == tmp[y]) {
                x++, y++;
                if (y == m) {
                    matches.push_back(x - y);
                    y = next[y]; // ���ݵ���һ�����ܵ�ƥ��λ��
                }
            } else {
                if (y == 0) {
                    x++;
                } else {
                    y = next[y];
                }
            }
        }

        return matches;
    }

private:
    // ���� next ����
    vector<int> md_next(const string &s) {
        int m = s.size();

        vector<int> next(m + 1);
        next[0] = -1;
        if (m == 1) {
            return next;
        }

        next[1] = 0;

        int i = 2;
        int cn = 0;
        while (i <= m) {
            if (s[i - 1] == s[cn]) {
                next[i++] = ++cn;
            } else if (cn > 0) {
                cn = next[cn];
            } else {
                next[i++] = 0;
            }
        }

        return next;
    }
};

// kmp��������ã�kmp�����ڱȽ��Ƿ�����Ե�
int computer(string &s1, string &s2, vector<int> &sk1, vector<int> &sk2, vector<int> &next) {
    int size = 0;
    int n = s1.size(), m = s2.size(), x = 0, y = 0;

    while (x < n) {
        if (s1[x] == s2[y]) {
            sk1[size] = x; // x -> y
            sk2[size] = y;
            x++, y++, size++;
        } else if (y == 0) {
            sk1[size] = x;
            sk2[size] = -1;
            size++, x++;
        } else {
            y = next[y];
        }
        if (y == m) {
            size -= m;
            y = size > 0 ? (sk2[size - 1] + 1) : 0;
        }
    }

    return size;
}

void Solve() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    vector<int> sk1(n), sk2(n);

    KMP kmp(s2);
    vector<int> next = kmp.next;
    int size = computer(s1, s2, sk1, sk2, next);

    for (int i = 0; i < size; i++) {
        cout << s1[sk1[i]];
    }
    cout << endl;
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
