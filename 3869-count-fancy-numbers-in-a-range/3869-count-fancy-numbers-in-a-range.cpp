class Solution {
public:
bool check(int n){
    string s=to_string(n);
    // cout << "checksum " << n << endl;
    if(s.size()<=1) return true;
     
     //incr

    if(s[0]<s[1]){
        int i=1;
        while(i<s.size()){
            if(s[i-1]>=s[i]) return false;
            i++;
        }
        return true;
    }
    
    //decr
     if(s[0]>s[1]){
        int i=1;
        while(i<s.size()){
            if(s[i-1]<=s[i]) return false;
            i++;
        }
        return true;
    }
    return false;
}
long long dp[16][2][2][140][2][2][12];
long long solve(int n,string& R,int tight,int leading,int sum,int inc,int dec,int last){
    
    if(n==0){
        // cout << "sum " << sum << endl;
        if(leading==1) return 0;
        if(inc || dec) return 1;
        if(check(sum)) return 1;
        return 0;
    }
    
    if(last!=-1 && dp[n][tight][leading][sum][inc][dec][last]!=-1) return dp[n][tight][leading][sum][inc][dec][last];
    long long ans=0;

    int upperB=tight ? R[R.size()-n]-'0' : 9;
     
     for(int deg=0;deg<=upperB;deg++){
          int new_leading=leading&(deg==0);
          if(new_leading) ans=ans+solve(n-1,R,tight&(deg==upperB),new_leading,sum,inc,dec,last);
          else if(last==-1){
             ans=ans+solve(n-1,R,tight&(deg==upperB),new_leading,sum+deg,1,1,deg);
          } else {
             int new_inc = inc && (deg > last);
            int new_dec = dec && (deg < last);
      ans=ans+solve(n-1, R,tight&(deg==upperB),new_leading,sum+deg, new_inc,new_dec,deg);
          }
     }
     
     if(last==-1) return ans;
     return dp[n][tight][leading][sum][inc][dec][last]=ans;
}
    long long countFancy(long long l, long long r) {
          string R=to_string(r);
          string L=to_string(l-1);
          
          memset(dp,-1,sizeof(dp));
          long long lft=solve(L.size(),L,1,1,0,0,0,-1);
         
          memset(dp,-1,sizeof(dp));
          long long rgt=solve(R.size(),R,1,1,0,0,0,-1);
         
        //  cout << lft << " " << rgt << endl; 

          return rgt-lft;

    }
};