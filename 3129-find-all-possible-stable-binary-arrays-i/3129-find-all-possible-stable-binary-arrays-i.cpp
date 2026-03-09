class Solution {
public:
int dp[201][201][201][2];
int MOD=1e9+7;
int solve(int zero,int one,int limit,int consecutive,bool last){
    if(zero==0 && one==0) return 1;

    int ans=0;
    
    if(dp[zero][one][consecutive][last]!=-1) return dp[zero][one][consecutive][last]; 
    if(consecutive==limit){
          //last - >false means last 0
          //last - >true means last 1
          if(last==1 && zero-1>=0) ans=(ans+solve(zero-1,one,limit,1,0))%MOD;
          if(last==0 && one-1>=0) ans=(ans+solve(zero,one-1,limit,1,1))%MOD;
    } else{
        if(zero>0){
            ans=(ans+solve(zero-1,one,limit, last==0 ? consecutive+1 : 1 ,0))%MOD;
        }
         if(one>0){
            ans=(ans+solve(zero,one-1,limit, last==1 ? consecutive+1 : 1 ,1))%MOD;
        }
    }
    return dp[zero][one][consecutive][last]=ans;
}
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        return solve(zero,one,limit,0,0);
    }
};