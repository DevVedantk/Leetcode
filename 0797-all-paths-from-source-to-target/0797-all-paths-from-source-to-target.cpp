class Solution {
public:
vector<vector<int>>ans;
  
  void solve(int node,vector<vector<int>>&adj,vector<int>&path){
    if(node==adj.size()-1){
        path.push_back(node);
        ans.push_back(path);
       path.pop_back();
        return;
    }
    
    path.push_back(node);
    for(int child:adj[node]){
        solve(child,adj,path);
    }
    path.pop_back();
  }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        
        vector<int>path;
        solve(0,adj,path);
         
         return ans;
    }
};