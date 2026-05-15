class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) {
         set<int>r_node;
         for(int i=0;i<res.size();i++){
              r_node.insert(res[i]);
         }

         vector<vector<int>>adj(n);
         for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
         }

         vector<bool>vis(n,false);

         queue<int>q;
         int cnt=0;
         
         if(r_node.find(0)==r_node.end()){
          q.push(0);
         }

         while(q.size()>0){
            int node=q.front();
            cnt++;
            q.pop();
            vis[node]=true;

            for(int child:adj[node]){
                if(r_node.find(child)==r_node.end() && !vis[child]){
                    q.push(child);
                }
            }
         }
         
         return cnt;
    }
};