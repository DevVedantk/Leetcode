class Solution {
public:
int dp[201][201][201];
vector<vector<int>>gcds;
int MOD=1e9+7;
int solve(int idx,int g1,int g2,vector<int>&arr){
     if(idx>=arr.size()){
        return (g1==g2 && g1!=0);
     }

     int ans=0;
     if(dp[idx][g1][g2]!=-1) return dp[idx][g1][g2];

     ans=(ans+solve(idx+1,g1==0 ? arr[idx] : gcds[g1][arr[idx]],g2,arr))%MOD;
     ans=(ans+solve(idx+1,g1,g2==0 ? arr[idx] : gcds[g2][arr[idx]],arr))%MOD;
     ans=(ans+solve(idx+1,g1,g2,arr))%MOD;

     return dp[idx][g1][g2]=ans;
}
    int subsequencePairCount(vector<int>& arr) {
          
    memset(dp,-1,sizeof(dp));
          
          gcds.assign(201,vector<int>(201,1));

          for(int i=0;i<=200;i++){
            for(int j=0;j<=200;j++){
                gcds[i][j]=gcd(i,j);
            }
          }
          return solve(0,0,0,arr);
    }
};