class Solution {
public:
vector<int>dist;
    void dfs(int node,int par,vector<vector<int>>&adj){
         
         for(int child:adj[node]){
            if(child==par) continue;
            dist[child]=1+dist[node];
            dfs(child,node,adj);
         }

    }
    int dp[100001][2];
    int MOD=1e9+7;
    int solve(int idx,int len,int sum){
        if(idx>=len){
            return (sum!=0);
        }
       if(dp[idx][sum]!=-1) return dp[idx][sum];
        int ans=0;
        ans=(ans+solve(idx+1,len,(sum+1)%2))%MOD;
        ans=(ans+solve(idx+1,len,(sum+2)%2))%MOD;

        return dp[idx][sum]=ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        dist.assign(n+1,0);
        dfs(1,-1,adj);
       int len=0;
       for(int e:dist) len=max(len,e);
       memset(dp,-1,sizeof(dp));

        return solve(0,len,0);
    }
};