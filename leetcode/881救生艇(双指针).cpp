#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;
        int sum = 0, ans = 0;
        while (l <= r)
        {
            sum = l == r ? people[l] : people[l] + people[r];
            if (sum > limit)
                r--;
            else
            {
                l++;
                r--;
            }
            ans++;
        }
        return ans;
    }
};