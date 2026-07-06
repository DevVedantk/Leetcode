class Solution {
public:
int dp[501][501]; 
int solve(int idx,int t,vector<int>&arr){
    if(idx>=arr.size()) return 0;

    int ans=0;
    if(dp[idx][t]!=-1) return dp[idx][t];
   
   ans=max(ans,arr[idx]*t+solve(idx+1,t+1,arr));
   ans=max(ans,solve(idx+1,t,arr));

   return dp[idx][t]=ans;
}
    int maxSatisfaction(vector<int>& arr) {
           memset(dp,-1,sizeof(dp));
         sort(arr.begin(),arr.end());
         return solve(0,1,arr);
    }
};