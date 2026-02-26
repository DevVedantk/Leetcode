class Solution {
public:
int dp[1001];
bool isP(string& s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;j--;
    }
    return true;
}
int solve(string& s,int start){
    if(start>=s.size()) return 0;

    int ans=0;
      
      if(dp[start]!=-1) return dp[start];
    for(int end=start;end<s.size();end++){
        string sub=s.substr(start,end-start+1);
        if(isP(sub)) ans++;
    }
    ans=ans+solve(s,start+1);
  
  return dp[start]=ans;


}
    int countSubstrings(string s) {
         memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};