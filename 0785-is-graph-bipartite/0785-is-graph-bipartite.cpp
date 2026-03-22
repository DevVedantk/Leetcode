class Solution {
public:
vector<int>color;
bool bfs(int node,int parent,vector<vector<int>>&adj){
      
      queue<int>q;
      q.push(node);

      color[node]=1;

      while(q.size()>0){
        int node=q.front();
        q.pop();

        for(int child:adj[node]){
            if(color[child]==-1){
              q.push(child);
              color[child]=1-color[node];
            } else if(color[child]==color[node]) return false;
        }
      }
      return true;

}

bool isBipartite(vector<vector<int>>& adj) {
         int n=adj.size();
         color.assign(n,-1);
          
          for(int i=0;i<n;i++){
            if(color[i]==-1){
          if(!bfs(i,-1,adj)) return false;
            }
          }
          return true;
    }
};