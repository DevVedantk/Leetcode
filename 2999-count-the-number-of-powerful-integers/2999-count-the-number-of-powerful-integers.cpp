class Solution {
public:
long long dp[17][2];
long long solve(string& R,int n,int tight,string& s,int lim){
    if(R.size()<s.size()) return 0ll;
     
     if(dp[n][tight]!=-1) return dp[n][tight];
     int upperB=tight ? (R[R.size()-n]-'0') : lim; 
     if(n==1){
      int last=s[s.size()-n]-'0';
      if(last>upperB) return 0ll;
      return 1ll;
     }
     long long ans=0;
     if(n<=s.size()){
        if(tight){
            int last=s[s.size()-n]-'0';
            if(last>upperB) return 0;
            else if(last==upperB) ans+=solve(R,n-1,1,s,lim);
            else return 1ll;
        } else return 1ll;
     } else{
        for(int deg=0;deg<=upperB && deg<=lim;deg++){
            ans+=solve(R,n-1,tight&(deg==upperB),s,lim);
        }
     }

     return dp[n][tight]=ans;
}
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
      string R=to_string(finish);
      string L=to_string(start-1);
     
     memset(dp,-1,sizeof(dp));
     long long ans1=solve(R,R.size(),1,s,limit);
 
     memset(dp,-1,sizeof(dp));
     long long ans2=solve(L,L.size(),1,s,limit);
     
     return ans1-ans2;
    }
};