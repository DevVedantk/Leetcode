class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
     
       vector<vector<int>>adj(n);
       for(int i=0;i<edges.size();i++){
        int a=edges[i][0],b=edges[i][1];
        adj[a].push_back(b);
       }
      
      vector<bool>vis(n,false);
      vector<int>ans;

        for(int i=0;i<n;i++){
            for(int ele:adj[i]){
                vis[ele]=true;
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==false) ans.push_back(i);
        }

        return ans;

    }
};