#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int ans = 0;
    int temp = K; // 初始化空座位数量

    for (int i = 0; i < N; ++i)
    {
        if (A[i] <= temp)
        {                 // 如果当前队列第一组人数小于等于剩余座位数
            temp -= A[i]; // 将当前队列第一组全部引导进入游乐项目
        }
        else
        { // 否则，需要启动游乐项目
            ans++;
            temp = K - A[i]; // 下一班的位置数目
        }
    }

    // 输出启动游乐项目的次数
    cout << ans + 1 << endl;

    return 0;
}
