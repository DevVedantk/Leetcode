class Solution {
public:
int dp[105][105][105];
// map<tuple<int,int,int>,int>dp;
int MOD=1e9+7;
int solve(int n,int minp,vector<int>& grp,vector<int>& profit,int idx,int currp){
  if(n<0) return 0;
  if(idx>=grp.size()) return (currp>=minp);
//   if(currp>=minp) return 1;
    
   if(dp[n][idx][currp]!=-1) return dp[n][idx][currp];
   int ans=0;
  if(n-grp[idx]>=0){
    int newp=min(currp+profit[idx],minp);
    ans=(ans+solve(n-grp[idx],minp,grp,profit,idx+1,newp))%MOD;
  }
  ans=(ans+solve(n,minp,grp,profit,idx+1,currp))%MOD;
  
  return dp[n][idx][currp]=ans;

}

int profitableSchemes(int n, int minp, vector<int>& group, vector<int>& profit) {
         memset(dp,-1,sizeof(dp));
        return solve(n,minp,group,profit,0,0);
    }
};