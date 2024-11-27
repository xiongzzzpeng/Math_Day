#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		char c;
		int num;
		cin >> c >> num;
		for(char ch = 'a'; ch <= 'h'; ch++)
			for(int j = 1; j <= 8; j++)
			{
				if((ch == c || j == num) && (ch != c || j != num))
					cout << ch << j <<' ';
			}
	}
	return 0;
}