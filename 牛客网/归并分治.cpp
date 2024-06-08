    // https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
    /*
        1��ʹ�����������+�Ҵ�+��Խ���Ҳ����Ĵ�
        2�����Ҹ�������᲻���������
    */

    #include <bits/stdc++.h>
    using namespace std;

    const int N = 100010;
    int arr[N], help[N], n;

    long merge(int l, int mid, int r) // ��Ҫ�������Ĺ���
    {
        long ans = 0;
        for (int j = mid + 1, i = l, sum = 0; j <= r; j++)
        {
            while (i <= mid && arr[i] <= arr[j])
            {
                sum += arr[i++];
            }
            ans += sum;
        }
        int i = l, a = l, b = mid + 1;
        while (a <= mid && b <= r)
        {
            help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
        }
        while (a <= mid)
            help[i++] = arr[a++];
        while (b <= r)
            help[i++] = arr[b++];
        for (i = l; i <= r; i++)
            arr[i] = help[i];   
        return ans;
    }

    long smallSum(int l, int r)
    {
        if (l == r)
            return 0;
        int mid = l + ((r - l) >> 1);
        return smallSum(l, mid) + smallSum(mid + 1, r) + merge(l, mid, r); // �� + �� + ��
    }

    int main()
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        printf("%ld", smallSum(0, n - 1));

        return 0;
    }
