class Solution {
public:

vector<int>depth;

void solve(int node,int parent,int end,vector<vector<int>>& adj,vector<int>& path,vector<int>& ans){
    path.push_back(node);
    if(node==end){
       ans=path;
       return;
    }

    for(int child:adj[node]){
       if(parent==child) continue;
       solve(child,node,end,adj,path,ans);
    path.pop_back();
    }

}

void dfs(int node,int parent,vector<vector<int>>& adj){
    
    for(int child:adj[node]){
        if(child==parent) continue;
       depth[child]=1+depth[node];
       dfs(child,node,adj);
    }
}


vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n==1) return {0};
         depth.assign(n+1,0);
         vector<vector<int>>adj(n+1);
         for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
         }

    dfs(0,-1,adj);
         int n1=-1,n2=-1;
         
         int maxnode=0,maxdist=0;
         for(int i=0;i<depth.size();i++){
          
          if(depth[i]>maxdist){
            maxdist=depth[i];
            maxnode=i;
          }
          depth[i]=0;
         }
       n1=maxnode;

         dfs(maxnode,-1,adj);

         int dia=0;
         for(int i=0;i<depth.size();i++){
            dia=max(dia,depth[i]);
         }

         for(int i=0;i<depth.size();i++){
            // if(n1==-1 && depth[i]==dia) n1=i;
             if(n2==-1 && depth[i]==dia) n2=i;
         }
       
        vector<int>path;
        vector<int>ans;
        solve(n1,-1,n2,adj,path,ans);
        vector<int>ht;
          int mid=ans.size()/2;
        if(ans.size()%2==0){
          ht.push_back(ans[mid]);
          ht.push_back(ans[mid-1]);
        } else ht.push_back(ans[mid]);

    return ht;


    }
};