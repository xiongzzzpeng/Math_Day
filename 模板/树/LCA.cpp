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

template <class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b != 0; b /= 2, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

template <int M>
struct ModInt {
   public:
    constexpr ModInt() : x(0) {}

    template <std::signed_integral T>
    constexpr ModInt(T x_) {
        T v = x_ % M;
        if (v < 0) {
            v += M;
        }
        x = v;
    }

    constexpr int val() const {
        return x;
    }

    constexpr ModInt operator-() const {
        ModInt res;
        res.x = (x == 0 ? 0 : M - x);
        return res;
    }

    constexpr ModInt inv() const {
        return power(*this, M - 2);
    }

    constexpr ModInt &operator*=(const ModInt &rhs) & {
        x = i64(x) * rhs.val() % M;
        return *this;
    }

    constexpr ModInt &operator+=(const ModInt &rhs) & {
        x += rhs.val();
        if (x >= M) {
            x -= M;
        }
        return *this;
    }

    constexpr ModInt &operator-=(const ModInt &rhs) & {
        x -= rhs.val();
        if (x < 0) {
            x += M;
        }
        return *this;
    }

    constexpr ModInt &operator/=(const ModInt &rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr ModInt operator*(ModInt lhs, const ModInt &rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend constexpr ModInt operator+(ModInt lhs, const ModInt &rhs) {
        lhs += rhs;
        return lhs;
    }

    friend constexpr ModInt operator-(ModInt lhs, const ModInt &rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend constexpr ModInt operator/(ModInt lhs, const ModInt &rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend constexpr std::istream &operator>>(std::istream &is, ModInt &a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }

    friend constexpr std::ostream &operator<<(std::ostream &os, const ModInt &a) {
        return os << a.val();
    }

    friend constexpr std::strong_ordering operator<=>(ModInt lhs, ModInt rhs) {
        return lhs.val() <=> rhs.val();
    }

   private:
    int x;
};

// M: Modulo value, should be prime.
// SIZE: size of precalculated values for factorial (n!) and its modular inverse.
template <int M, typename T = ModInt<M>>
struct Comb {
    std::vector<T> fac;
    std::vector<T> facInv;
    constexpr static int MAX = 4194304;

    Comb() {
        fac.assign(1, 1);
        facInv.assign(1, 1);
    }

    template <std::signed_integral U>
    T P(U n, U m) {
        assert(n >= 0 && m >= 0 && m <= n);
        if (n >= MAX) {
            T res = 1;
            while (m--) res *= n--;
            return res;
        }
        enlarge(n);
        return fac[n] * facInv[n - m];
    }

    template <std::signed_integral U>
    T C(U n, U m) {
        auto res = P(n, m);
        enlarge(m);
        return facInv[m] * res;
    }

    bool enlarge(int n) {
        if (n >= MAX) return false;
        if (n >= fac.size()) {
            int sz = fac.size();
            int nsz = std::bit_ceil(unsigned(n + 1));
            fac.resize(nsz);
            facInv.resize(nsz);
            for (int i = sz; i < nsz; i++) {
                fac[i] = fac[i - 1] * i;
                facInv[i] = fac[i].inv();
            }
        }
        return true;
    }

    // Lucas's theorem: C(a,b) % M.
    template <std::signed_integral U>
    T lucas(U a, U b) {
        T res = 1;
        while (a && b) {
            U ma = a % M, mb = b % M;
            if (ma < mb) return 0;
            res *= C(ma, mb);
            a /= M, b /= M;
        }
        return res;
    }

    T catalan(int n) {
        return C(2 * n, n) / (n + 1);
    }
};

constexpr int M = 1e9 + 7;
using Z = ModInt<M>;
Comb<M> comb;

template <std::signed_integral U>
Z P(U n, U m) {
    return comb.P(n, m);
}

template <std::signed_integral U>
Z C(U n, U m) {
    return comb.C(n, m);
}

// LCA on tree using Heavy-Light Decomposition.
struct Lca {
    vector<vector<int>> &d;
    int root;
    // siz: subtree vertex count.
    // dep: depth, root as 0.
    // son: heavy son vertex id.
    // top: top vertex of current heavy path.
    vector<int> fa, siz, son, dep, top;

    Lca(vector<vector<int>> &d_, int root_) : d(d_), root(root_) {
        int n = d.size();
        fa.assign(n, 0);
        siz.assign(n, 0);
        son.assign(n, 0);
        dep.assign(n, 0);
        top.assign(n, 0);
        dfs1(root);
        dfs2(root, root);
    }

    void dfs1(int x) {
        siz[x] = 1;
        dep[x] = dep[fa[x]] + 1;
        for (int to : d[x]) {
            if (to != fa[x]) {
                fa[to] = x;
                dfs1(to);
                siz[x] += siz[to];
                if (siz[to] > siz[son[x]]) son[x] = to;
            }
        }
    }

    void dfs2(int x, int tp) {
        top[x] = tp;
        if (son[x]) dfs2(son[x], tp);
        for (int to : d[x]) {
            if (to != fa[x] && to != son[x]) dfs2(to, to);
        }
    }

    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            u = fa[top[u]];
        }
        if (dep[u] < dep[v])
            return u;
        else
            return v;
    }
};

void Solve() {
    int n;
    cin >> n;

    vector<int> flag(n + 1);
    for (int i = 2; i * i <= n; i++) {
        if (!flag[i]) {
            for (int j = i * i; j <= n; j += i) {
                flag[j] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!flag[i]) {
            cnt++;
        }
    }

    cout << cnt << endl;
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
