class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(int i=1;i<n;i++){
            adj[i].push_back({i+1,1});
            adj[i+1].push_back({i,1});
        }
        adj[x].push_back({y,1});
        adj[y].push_back({x,1});
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));

        for(int i=1;i<=n;i++) dp[i][i]=0;
        
        for(int i=1;i<=n;i++){
            int u=i;
            for(auto [v,wt]:adj[i]){
                dp[u][v]=min(dp[u][v],wt);
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }

        vector<int>ans(n);
        for(int k=1;k<=n;k++){
            int cnt=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dp[i][j]==k) cnt++;
                }
            }
            ans[k-1]=cnt;
        }
         
         return ans;

    }
};