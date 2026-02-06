class Solution {
public:
int dp[1001][1001];
int solve(int i,int j,string& s1,string& s2){
    if(i>=s1.size() || j>=s2.size()){
        int sum=0;
        while(i<s1.size()) sum+=(int)s1[i++];
        while(j<s2.size())  sum+=(int)s2[j++];
        return sum;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    if(s1[i]==s2[j]) ans=min(ans,solve(i+1,j+1,s1,s2));
    else{
    ans=min(ans,(int)s1[i]+solve(i+1,j,s1,s2));
    ans=min(ans,(int)s2[j]+solve(i,j+1,s1,s2));
    }
    return  dp[i][j]=ans;
}
    int minimumDeleteSum(string s1, string s2) {
     memset(dp,-1,sizeof(dp));
        return solve(0,0,s1,s2);
    }
};