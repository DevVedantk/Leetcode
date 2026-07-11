class Solution {
public:
vector<bool>vis;

int solve(int node,vector<vector<int>>&adj){
     
     if(adj[node].size()==0) return 0;

     int ans=0;
     vis[node]=true;

     for(int child:adj[node]){
         if(!vis[child]){
            ans=ans+solve(child,adj)+1;
         }
     }

     return ans;        
}
vector<bool>vis2;
bool check(int node,int par,int size,vector<vector<int>>&adj){
    if(adj[node].size()!=size-1) return false;
    
    vis2[node]=true;
    for(int child:adj[node]){
         if(!vis2[child]){
        if(!check(child,node,size,adj)) return false;
         } 
    }

    return true;
}

int countCompleteComponents(int n, vector<vector<int>>& edges) {
         
         vector<vector<int>>adj(n);
         for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
             
            adj[u].push_back(v);
            adj[v].push_back(u);
         }

         vis.assign(n,false);
         vis2.assign(n,false);
         int cnt=0;

         for(int i=0;i<n;i++){
            if(!vis[i]){
                int size=solve(i,adj)+1;
                if(check(i,-1,size,adj)) cnt++;
            }
         } 
       return cnt;


    }
};