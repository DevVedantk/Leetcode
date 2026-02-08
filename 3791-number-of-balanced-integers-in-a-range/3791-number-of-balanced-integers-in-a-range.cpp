class Solution {
public:
long long dp[17][2][2][140][140][2];
long long solve(string& R,int n,int leading,int tight,int evensum,int oddsum,int parity){
   if(n==0){
       if(leading==0) return (evensum==oddsum);
       return 0;
   }
    if(dp[n][leading][tight][evensum][oddsum][parity]!=-1) return
        dp[n][leading][tight][evensum][oddsum][parity];
    
    int upperB= tight ? R[R.size()-n]-'0' : 9;
    long long ans=0;
    for(int deg=0;deg<=upperB;deg++){
        int newleading=leading&(deg==0);

        // if(newleading) ans+=solve(R,n-1,newleading,tight&(deg==upperB),evensum,oddsum,parity);
        if(parity==1) ans+=solve(R,n-1,newleading,tight&(deg==upperB),evensum,oddsum+deg,0); 
        else ans+=solve(R,n-1,newleading,tight&(deg==upperB),evensum+deg,oddsum,1); 
    }
    return dp[n][leading][tight][evensum][oddsum][parity]=ans;
    
}    
    long long countBalanced(long long low, long long high) {

        string L=to_string(low-1);
        string R=to_string(high);

        memset(dp,-1,sizeof(dp));
       long long ans1=solve(R,R.size(),1,1,0,0,1);
        // cout << ans1 << endl;
        memset(dp,-1,sizeof(dp));
       long long ans2=solve(L,L.size(),1,1,0,0,1);
        return ans1-ans2;
    }
};