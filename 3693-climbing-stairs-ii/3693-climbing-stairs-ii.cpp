class Solution {
public:
int dp[100001];
int solve(int n,vector<int>& arr,int idx){
   if(idx>=n) return 0;
   
   if(dp[idx]!=-1) return dp[idx];
   int ans=1e9;
  if(idx<n) ans=min(ans,(1+arr[idx])+solve(n,arr,idx+1));
   if(idx+1<n) ans=min(ans,(4+arr[idx+1])+solve(n,arr,idx+2));
  if(idx+2<n)  ans=min(ans,(9+arr[idx+2])+solve(n,arr,idx+3));

   return dp[idx]=ans;
}

int climbStairs(int n, vector<int>& costs) {
         memset(dp,-1,sizeof(dp));
        return solve(n,costs,0);
    }
};