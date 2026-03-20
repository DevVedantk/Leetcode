class Solution {
public:
vector<bool>vis;

bool dfs(vector<vector<int>>&adj,int src,int des){
    if(src==des){
        return true;
    }


    vis[src]=true;
    for(int child:adj[src]){
        if(vis[child]==false){
           if(dfs(adj,child,des)) return true;
        }
    }
    return false;

}
    bool validPath(int n, vector<vector<int>>& ed, int src, int des) {
        
        vector<vector<int>>adj(n);
        vis.assign(n,false);
        for(int i=0;i<ed.size();i++){
                int a=ed[i][0],b=ed[i][1];
                adj[a].push_back(b);
                adj[b].push_back(a);
            
        }

    return dfs(adj,src,des);

    }
};