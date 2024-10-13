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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// ÆÕÍ¨¶þ²æÊ÷
class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if (l && r) {
            return root;
        }
        if (!l && !r) {
            return NULL;
        }
        return l == NULL ? r : l;
    }
};

// ËÑË÷¶þ²æÊ÷
class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root->val != q->val && root->val != p->val) {
            if (root->val > min(p->val, q->val) && root->val < max(p->val, q->val)) {
                break;
            }
            root = root->val < min(p->val, q->val) ? root->right : root->left;
        }
        return root;
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
