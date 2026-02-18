class Solution {
public:
map<int,vector<int>>mp;
int dp[101][101];
int solve(int i,int j,string& ring,string& key){
    if(i==key.size()) return 0;
     int n=ring.size();
      
      if(dp[i][j]!=-1) return dp[i][j];
     int ans=1e9;
      
      int currentCharPos=key[i]-'a';
      
      for(int pos:mp[currentCharPos]){
        int diff=abs(pos-j);
        int steps=min(diff,n-diff);
        ans=min(ans,steps+1+solve(i+1,pos,ring,key));
      }
      return dp[i][j]=ans;
      
     
}
    int findRotateSteps(string ring, string key) {

       for(int i=0;i<ring.size();i++) mp[ring[i]-'a'].push_back(i);
       memset(dp,-1,sizeof(dp));
       return solve(0,0,ring,key);        
    }
};