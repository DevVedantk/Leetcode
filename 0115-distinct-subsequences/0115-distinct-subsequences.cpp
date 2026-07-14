class Solution {
public:
     int dp[1001][1001];
    int solve(string& s,string& t,int idx1,int idx2){
        
        if(idx1>=s.size() || idx2>=t.size()){
           return (idx2>=t.size());
        }
    
        int ans=0;
       if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s[idx1]==t[idx2]){
            ans=ans+solve(s,t,idx1+1,idx2+1);
        }
        ans=ans+solve(s,t,idx1+1,idx2);
        return dp[idx1][idx2]=ans;


    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0); 
    }
};