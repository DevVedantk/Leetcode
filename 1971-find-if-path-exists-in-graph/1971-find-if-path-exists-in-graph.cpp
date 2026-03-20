class Solution {
public:
vector<bool>vis;

void dfs(vector<vector<int>>&adj,int src){
 
   vis[src]=true;
    for(int child:adj[src]){
        if(vis[child]==false){
           dfs(adj,child);
        }
    }

}
    bool validPath(int n, vector<vector<int>>& ed, int src, int des) {
        
        vector<vector<int>>adj(n);
        vis.assign(n,false);
        for(int i=0;i<ed.size();i++){
                int a=ed[i][0],b=ed[i][1];
                adj[a].push_back(b);
                adj[b].push_back(a);
            
        }

     dfs(adj,src);
   return vis[des];
    }
};