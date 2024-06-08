class Solution
{
public:
    long long minimumRemoval(vector<int> &beans)
    {
        ranges::sort(beans);
        long long sum = 0, mx = 0;
        int n = beans.size();
        for (int i = 0; i < n; i++)
        {
            sum = sum + beans[i];
            mx = max(mx, (long long)(n - i) * beans[i]);
        }
        return sum - mx;
    }
};
// 据体注释就不写了，看“灵茶山艾府”的题解，真的是天才