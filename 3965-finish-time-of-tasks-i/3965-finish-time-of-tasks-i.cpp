class Solution {
public:
vector<long long>ftime;
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&basetime){

           //leaf node 
          if(adj[node].size()==1 && node!=0) {
             ftime[node]=(long long)basetime[node];
             return;
          } 
           
           long long mxtime=LLONG_MIN,mntime=LLONG_MAX;

          for(int child:adj[node]){
              if(child==parent) continue;
              dfs(child,node,adj,basetime);
              mxtime=max(mxtime,ftime[child]);
              mntime=min(mntime,ftime[child]);
          }
          //non leaf
         if(mxtime!=LLONG_MIN && mntime!=LLONG_MAX) ftime[node]=mxtime+(mxtime-mntime+(long long)basetime[node]); 
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
         ftime.assign(n,0);
         if(edges.size()==0) return baseTime[0];
         
         vector<vector<int>>adj(n);

         for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
         }

        dfs(0,-1,adj,baseTime);
        
        return ftime[0];
    }
};