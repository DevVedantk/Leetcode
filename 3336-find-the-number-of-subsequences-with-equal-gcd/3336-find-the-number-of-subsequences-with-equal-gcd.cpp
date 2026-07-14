class Solution {
public:
int dp[201][201][201];
int MOD=1e9+7;
int solve(int idx,int g1,int g2,vector<int>&arr){
     if(idx>=arr.size()){
        return (g1==g2 && g1!=0);
     }

     int ans=0;
     if(dp[idx][g1][g2]!=-1) return dp[idx][g1][g2];

     ans=(ans+solve(idx+1,gcd(g1,arr[idx]),g2,arr))%MOD;
     ans=(ans+solve(idx+1,g1,gcd(g2,arr[idx]),arr))%MOD;
     ans=(ans+solve(idx+1,g1,g2,arr))%MOD;

     return dp[idx][g1][g2]=ans;
}
    int subsequencePairCount(vector<int>& arr) {
          
    memset(dp,-1,sizeof(dp));
          return solve(0,0,0,arr);
    }
};