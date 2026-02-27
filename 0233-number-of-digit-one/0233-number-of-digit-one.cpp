class Solution {
public:
int dp[11][2][11];
int solve(string& s,int idx,int cnt,int tight){
    if(idx==s.size()) return cnt;
    if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];

    int limit=(tight==1?s[idx]-'0':9);
    int ans=0;
    for(int i=0;i<=limit;i++){
        int updateCnt=cnt+(i==1?1:0);
      ans+=solve(s,idx+1,updateCnt,tight&(i==s[idx]-'0'));  
    }
    return dp[idx][tight][cnt]=ans;

}
    int countDigitOne(int n) {
     memset(dp,-1,sizeof(dp));
          string r=to_string(n);
          return solve(r,0,0,1); 
    }
};