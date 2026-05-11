class Graph {
public:
vector<vector<pair<int,int>>>adj;
vector<vector<int>>dp;
    Graph(int n, vector<vector<int>>& edges) {
         adj.resize(n);
         for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1],wt=edges[i][2];
            adj[u].push_back({v,wt});
         }
         dp.assign(n,vector<int>(n,INT_MAX));

         for(int i=0;i<n;i++){
            dp[i][i]=0;
         }

         for(int i=0;i<n;i++){
            int u=i;
            for(auto [v,wt]:adj[i]){
                dp[u][v]=min(dp[u][v],wt);
            }
         }

         for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                    }
                }
            }
         }
    }
    
    void addEdge(vector<int> edge) {
         int u=edge[0],v=edge[1],wt=edge[2];
         
           for(int i=0;i<dp.size();i++){
                for(int j=0;j<dp.size();j++){
                    if(dp[i][u]!=INT_MAX && dp[v][j]!=INT_MAX){
                    dp[i][j]=min(dp[i][j],dp[i][u]+wt+dp[v][j]);
                    }
                }
            }

    }
    
    int shortestPath(int node1, int node2) {
        if(dp[node1][node2]==INT_MAX) return -1;
        return dp[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */