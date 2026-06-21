class Solution {
public:
long long dp[16][2][2][10];
  long long solve(string& R,int n,int tight,int leading,int prevTaken,int k){
     
     if(n==0){
        if(leading) return 0;
        return 1;
     }
     long long ans=0;
     if(prevTaken!=-1 && dp[n][tight][leading][prevTaken]!=-1) 
     return dp[n][tight][leading][prevTaken];

     int upperB=tight ? R[R.size()-n]-'0' : 9;
     
     for(int deg=0;deg<=upperB;deg++){
        int newleading=leading&(deg==0);


        if(newleading){
            ans+=solve(R,n-1,tight&(deg==upperB),newleading,prevTaken,k);
        } 
        else if(prevTaken==-1){
            ans+=solve(R,n-1,tight&(deg==upperB),newleading,deg,k);
        }
        else if(abs(prevTaken-deg)<=k){
           ans+=solve(R,n-1,tight&(deg==upperB),newleading,deg,k);
        }
     }
     if(prevTaken==-1) return ans;

     return dp[n][tight][leading][prevTaken]=ans;

  }
    long long goodIntegers(long long l, long long r, int k) {
         
           string R=to_string(r);
   string L=to_string(l-1);
   

      //0 to R
     memset(dp,-1,sizeof(dp));
   long long ans1=solve(R,R.size(),1,1,-1,k);
     memset(dp,-1,sizeof(dp));
   long long ans2=solve(L,L.size(),1,1,-1,k);
   
//    cout << ans1-ans2 << endl;
     return ans1-ans2;
    }
};