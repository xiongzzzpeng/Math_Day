#include <bits/stdc++.h>
using namespace std;


void sove()
{
	string str , ans;
	cin >> str;
	vector<bool> st(str.size());
	int sb = 0 , lb = 0;
	for(int i = str.size() - 1; i >= 0; i--)
	{
		if(str[i] == 'b')
		{
			sb++;
		}
		else if(str[i] == 'B')	
		{
			lb++;
		}
		else 
		{
			if(str[i] >= 'a' && str[i] <= 'z')
		{
			if(sb)
			{
				sb--;
			}
			else
			{
				st[i] = true;
			}
		}
		else
		{
			if(lb)
			{
				lb--;
			}
			else
			{
				st[i] = true;
			}
		}
		}
	}
	
	for(int i = 0; i < str.size(); i++)
	{
		if(st[i])
			ans = ans + str[i];
	}
	cout << ans << "\n";
}


int main()
{
	std::ios::sync_with_stdio(false); //能提高代码运行速率，试一试
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t ;
	cin >> t;
	while(t--)
	{
		sove();
	}
	
	return 0;
}