class Solution {
public:

long long dp[16][2][2][10][10][16];
long long solve(string& R,int n,int tight,int lead,int first,int sec,int currAns){
    if(n==0) return currAns;

    long long ans=0;

    if(first!=-1 && sec!=-1 && dp[n][tight][lead][first][sec][currAns]!=-1) return
    dp[n][tight][lead][first][sec][currAns];

    
    int upperB=tight? (R[R.size()-n]-'0') : 9;

    for(int deg=0;deg<=upperB;deg++){
        int newlead=lead && (deg==0);
         int newans=currAns;

        if(first!=-1 && sec!=-1 && newlead==0){
            if(first<sec && sec>deg) newans++;
            else if(first>sec && sec<deg) newans++;
        }
        int newfirst=first;
        int newsec=sec;

        if(!newlead){
           newfirst=sec;
           newsec=deg;
        }
     
      ans=ans+solve(R,n-1,tight&(deg==upperB),newlead,newfirst,newsec,newans);
    }
    if(first==-1 || sec==-1) return ans;
    return  dp[n][tight][lead][first][sec][currAns]=ans;

}
    long long totalWaviness(long long num1, long long num2) {
        
        string R=to_string(num2);
        string L=to_string(num1-1);
        
        memset(dp,-1,sizeof(dp));
    long long ans1=solve(R,R.size(),1,1,-1,-1,0);
        memset(dp,-1,sizeof(dp));
    long long ans2=solve(L,L.size(),1,1,-1,-1,0);
        return ans1-ans2;
    }
};