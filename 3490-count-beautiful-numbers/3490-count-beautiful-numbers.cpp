class Solution {
public:
int pa[10],pb[10],pc[10],pd[10];

map<tuple<int,int,int,int,int,int,int,int,int>,long long>dp;
bool check(int two,int three,int five,int seven,int sum){
   long long ans=1;
   for(int i=0;i<two;i++) ans*=2;
   for(int i=0;i<three;i++) ans*=3;
   for(int i=0;i<five;i++) ans*=5;
   for(int i=0;i<seven;i++) ans*=7;
   return (ans%sum==0);
}
int solve(string& R,int n,int tight,int leading,int degsum,int a,int b,int c,int d,int zero){
     if(n==0){
         if(degsum==0 || zero==1) return 1;
         return check(a,b,c,d,degsum);
     }
     
    //  if(dp[n][tight][leading][degsum][a][b][c][d]!=-1) return dp[n][tight][leading][degsum][a][b][c][d];
    auto pair=make_tuple(n,tight,leading,degsum,a,b,c,d,zero);
    if(dp.find(pair)!=dp.end()) return dp[pair];
     int ans=0;
     int upperB=tight ? (R[R.size()-n]-'0') : 9;

     for(int deg=0;deg<=upperB;deg++){
        int newleading=leading&&(deg==0);
        int na=a+pa[deg];
        int nb=b+pb[deg];
        int nc=c+pc[deg];
        int nd=d+pd[deg];
        int newz=zero;
        if(deg==0 && newleading==0) newz=1;
        ans+=solve(R,n-1,tight&(deg==upperB),newleading,degsum+deg,na,nb,nc,nd,newz);
     }
     return dp[pair]=ans;

}
    int beautifulNumbers(int l, int r) {
        string R=to_string(r);
        string L=to_string(l-1);
        
        int primes[4]={2,3,5,7};
        for(int d=0;d<=9;d++){
            int x=d;
          for(int i=0;i<4;i++){
            int p=primes[i];
            while(x && x%p==0){
                if(p==2) pa[d]++;
                if(p==3) pb[d]++;
                if(p==5) pc[d]++;
                if(p==7) pd[d]++;
                x/=p;
            }
          }
        }
       
        // memset(dp,-1,sizeof(dp));
        int ans1=solve(R,R.size(),1,1,0,0,0,0,0,0);
        
        dp.clear();
        int ans2=solve(L,L.size(),1,1,0,0,0,0,0,0);
       
        return ans1-ans2; 
        
    }
};