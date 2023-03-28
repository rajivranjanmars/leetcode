class Solution {
public:
int solve(vector<int>& days, vector<int>& costs,int idx,int n,vector<int>&dp){

if(idx>=n)
return 0;

if(dp[idx]!=-1)
return dp[idx];
int l=INT_MAX, r=INT_MAX, m=INT_MAX;
// take one day pass
l=costs[0]+solve(days,costs,idx+1,n,dp);
int x=days[idx]+6;
int pos=-1;
int i=idx;
for(i=idx;i<n;i++){
    if(days[i]>x)
    break;
}
r=costs[1]+solve(days,costs,i,n,dp);

x=days[idx]+29;
i=idx;
for(i=idx;i<n;i++)
{
    if(days[i]>x)
    break;
}
m= costs[2]+solve(days,costs,i,n,dp);

return dp[idx]=min(min(l,r),m);
}  
    int mincostTickets(vector<int>& days, vector<int>& costs) {
int n=days.size();
vector<int>dp(n,-1);
return solve(days,costs,0,n,dp);
    }
};