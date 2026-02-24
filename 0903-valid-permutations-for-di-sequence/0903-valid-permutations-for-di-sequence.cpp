class Solution {
public:
vector<vector<vector<int>>>dp;
int MOD=1e9+7;
    int solve(string& s, int idx, int prev, vector<bool>& vis, int prevele) {
        if (idx>s.size()) return 1;
        int ans = 0;
   
   if(prev!=-1 && prevele!=-1 && dp[idx][prev][prevele]!=-1) return dp[idx][prev][prevele];
       for(int i=0;i<vis.size();i++) {
           if(vis[i]) continue;
            // Create a new set for recursion
           
            if (prev == -1 ) {
                //  if(vis[i]==)
                vis[i]=true;
                ans = (ans + solve(s, idx + 1, s[idx] == 'D' ? 1 : 0, vis,i))%MOD;
                vis[i]=false;
            } else if (prev == 1 && i > prevele) {
                vis[i]=true;
                ans = (ans + solve(s, idx + 1, s[idx] == 'D' ? 1 : 0, vis,i))%MOD;
                vis[i]=false;
            } else if (prev == 0 && i< prevele) {
                vis[i]=true;
                ans= (ans + solve(s, idx + 1, s[idx] == 'D' ? 1 : 0, vis,i))%MOD;
                vis[i]=false;
            }
           
        }
       
       if(prev==-1 || prevele==-1 ) return ans;
        return dp[idx][prev][prevele]=ans;
    }

    int numPermsDISequence(string s) {
        int n = s.size();
        dp.assign(n+1,vector<vector<int>>(3,vector<int>(n+1,-1)));
        // memset(dp,-1,sizeof(dp));
        vector<bool>vis(n+1,false);
        return solve(s, 0, -1, vis, -1);
    }
};