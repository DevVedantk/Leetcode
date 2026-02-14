class Solution {
public:
int MOD=1e9+7;
int dp[100001][2][3];
int solve(int idx,int A,int L){
    if(idx==0) return 1;
    int ans=0;
    if(dp[idx][A][L]!=-1) return dp[idx][A][L];
    
    if(A==0) ans=(ans+solve(idx-1,A+1,0))%MOD;
    if(L<2) ans=(ans+solve(idx-1,A,L+1))%MOD;
    ans=(ans+solve(idx-1,A,0))%MOD;
   
   return dp[idx][A][L]=ans;
}
    int checkRecord(int n) {
      memset(dp,-1,sizeof(dp));
       return solve(n,0,0); 
    }
};