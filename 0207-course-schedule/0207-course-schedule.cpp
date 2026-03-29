class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
           
           vector<int>deg(n);
           vector<vector<int>>adj(n);
           for(int i=0;i<edges.size();i++){
            deg[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
           }

          queue<int>q;
          for(int i=0;i<n;i++){
             if(deg[i]==0) q.push(i); 
          }      
    
    vector<int>res;
    while(q.size()>0){
        int node=q.front();
        q.pop();
      
      res.push_back(node);
        for(int child:adj[node]){
            deg[child]--;
            if(deg[child]==0) q.push(child);
        }
    }

    return (res.size()==n);
           

    }
};