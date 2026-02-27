class Solution {
public:
int MOD=1e9+7;
string subtractOne(string s) {
    int i = s.size() - 1;
    while (i >= 0) {
        if (s[i] > '0') {
            s[i]--;
            break;
        } else {
            s[i] = '9';
            i--;
        }
    }
     int pos=0;
     while(s[pos]!=0) pos++;
     if(pos>=s.size()) return s;
     if(pos==s.size()-1) return "0";
     else return s.substr(pos);
}

int solve(string& R,int mins,int maxs,int n,int curr_sum,bool tight,int dp[24][2][401]){
   if(n==0){
     if(curr_sum>=mins && curr_sum<=maxs) return 1;
     return 0;
   }
   
   if(dp[n][tight][curr_sum]!=-1) return dp[n][tight][curr_sum];
   int upperb=tight ? (R[R.size()-n]-'0') : 9;
    
    int ans=0;
    for(int deg=0;deg<=upperb;deg++){
     ans=(ans%MOD+solve(R,mins,maxs,n-1,curr_sum+deg,(tight & (upperb==deg)),dp)%MOD)%MOD;
    }
    return dp[n][tight][curr_sum]=ans%MOD;
}

    int count(string num1, string num2, int mins, int maxs) {
        int dp[24][2][401];
        memset(dp,-1,sizeof(dp));
        string L=subtractOne(num1);
        int c1=solve(L,mins,maxs,L.size(),0,1,dp)%MOD;
          memset(dp,-1,sizeof(dp));
        int c2=solve(num2,mins,maxs,num2.size(),0,1,dp)%MOD;

        return ((c2 - c1) % MOD + MOD) % MOD;
    }
};