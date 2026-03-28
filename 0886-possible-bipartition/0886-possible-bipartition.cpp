class Solution {
public:
vector<int>color;
bool dfs(int node,vector<vector<int>>&adj){
    for(int child:adj[node]){
        if(color[child]==-1){
            color[child]=1-color[node];
           if(!dfs(child,adj)) return false;
        } else if(color[node]==color[child]) return false;
    }

    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);
        color.assign(n+1,-1);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                color[i]=1;
            if(!dfs(i,adj)) return false;
            }
        }

        return true;
    }
};