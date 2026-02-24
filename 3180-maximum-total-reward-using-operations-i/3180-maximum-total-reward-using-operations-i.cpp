class Solution {
public:

int dp[2001][4001];
int solve(vector<int>& arr,int idx,int reward){
   if(idx>=arr.size()) return reward;
   int ans=0;
  if(dp[idx][reward]!=-1) return dp[idx][reward];
   if(arr[idx]>reward)
   ans=max(ans,solve(arr,idx+1,reward+arr[idx]));

   ans=max(ans,solve(arr,idx+1,reward));
   return dp[idx][reward]=ans;
}

int maxTotalReward(vector<int>& arr) {
        sort(arr.begin(),arr.end());
      memset(dp,-1,sizeof(dp));
        return solve(arr,0,0);
    }
};