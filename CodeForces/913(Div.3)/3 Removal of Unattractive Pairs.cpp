#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
分两种情况
1、最多的超占了总数的一半，最多的肯定约不完，ans = 总数 - 2*其他
2、最多的没超过一半，最多肯定能约完，其他就看奇偶性了，ans = 总数 % 2
*/

void solve()
{
	int cen[26] = {0};
	int n;
	int mx = 0;
	string s;
	cin >> n >> s;
	int len = s.size();
	for(int i = 0; i < len; i++)
	{
		cen[s[i] - 'a']++;
		mx = max(mx , cen[s[i] - 'a']);
	}
	int ans;
	if(mx > n/2)
		ans = n - 2*(n - mx);
	else
		ans = n % 2;
	cout << ans << endl;
}



int main()
{
	std::ios::sync_with_stdio(false); 
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int s;
	cin >> s;
	while(s--){
		solve();
	}
	
	
	return 0;
}
