class Solution {
public:

vector<int>dep;
void dfs(int node,int parent,vector<vector<int>>& adj){

       for(int child:adj[node]){
        if(child==parent) continue;
        dep[child]=1+dep[node];
        dfs(child,node,adj);
       } 
}

int dp[100001][2];
int MOD=1e9+7;

int solve(int idx,int n,int sum){
   if(idx>=n) return (sum==1);
   int ans=0;
   
   if(dp[idx][sum]!=-1) return dp[idx][sum];
   ans=(ans+solve(idx+1,n,(sum+1)%2))%MOD;
   ans=(ans+solve(idx+1,n,(sum+2)%2))%MOD;
   return dp[idx][sum]=ans;
}

int assignEdgeWeights(vector<vector<int>>& edges) {
          int n=edges.size()+1;
   
   dep.assign(n+1,0);
          vector<vector<int>>adj(n+1);

          for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
          }

          dfs(1,-1,adj);
          memset(dp,-1,sizeof(dp));
          int len=0;
          for(int i=0;i<dep.size();i++){
            len=max(len,dep[i]);
          }
     
     int ans=solve(0,len,0);
          return ans;
    }
};