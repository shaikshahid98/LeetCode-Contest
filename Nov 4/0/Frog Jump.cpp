#include <bits/stdc++.h>
using namespace std; 
void solve(int ind,int n,vector<int> &h,vector<int> &dp)
{
    if(ind == n)  return;
      solve(ind+1,n,h,dp);
    if(ind+1 < n)
    {
    dp[ind] = min(dp[ind],dp[ind+1] + abs(h[ind]-h[ind+1]));
    }
    if(ind + 2 < n)
    {
    int op1 = min( dp[ind+2] + abs(h[ind+2]-h[ind]) , dp[ind+1]+abs(h[ind+1] - h[ind]) );

        dp[ind] = min(dp[ind],op1);
    }

  
    return;
}
int frogJump(int n, vector<int> &h)
{
    vector<int> dp(n,INT_MAX);
    dp[n-1]=0;
    solve(0,n,h,dp);
    return dp[0];
}