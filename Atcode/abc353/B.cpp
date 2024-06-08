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
    int temp = K; // ��ʼ������λ����

    for (int i = 0; i < N; ++i)
    {
        if (A[i] <= temp)
        {                 // �����ǰ���е�һ������С�ڵ���ʣ����λ��
            temp -= A[i]; // ����ǰ���е�һ��ȫ����������������Ŀ
        }
        else
        { // ������Ҫ����������Ŀ
            ans++;
            temp = K - A[i]; // ��һ���λ����Ŀ
        }
    }

    // �������������Ŀ�Ĵ���
    cout << ans + 1 << endl;

    return 0;
}
