class Solution {
public:
vector<int>subtreeNodes;
vector<int>ans;
vector<int>depth;

int findSubTreeNode(int node,int parent,vector<vector<int>>& adj){
    int cnt=1;
    for(int child:adj[node]){
          if(parent==child) continue;
        cnt+=findSubTreeNode(child,node,adj);
    }
    subtreeNodes[node]=cnt;
    return cnt;
}

void dfs(int node,int parent,vector<vector<int>>& adj){
     for(int child:adj[node]){
        if(parent==child) continue;
        depth[child]=1+depth[node];
        dfs(child,node,adj);
     }
}

void solve(int node,int parent,vector<vector<int>>& adj,int n){
     for(int child:adj[node]){
        if(parent==child) continue;
        int x=subtreeNodes[child];
        ans[child]=ans[node]-x+(n-x);
        solve(child,node,adj,n);
     }

}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        subtreeNodes.assign(n,0);
        ans.assign(n,0);
        depth.assign(n,0);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        findSubTreeNode(0,-1,adj);
       
      
        dfs(0,-1,adj);

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=depth[i];
        }
        ans[0]=sum;
    

        solve(0,-1,adj,n);

  return ans;

    }
};