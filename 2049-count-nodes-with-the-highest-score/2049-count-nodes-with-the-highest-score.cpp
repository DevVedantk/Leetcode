class Solution {
public:
vector<int>subsize;
vector<long long>ans;
int dfs(int node,int parent,vector<vector<int>>& adj){
    int cnt=1;
    for(int child:adj[node]){
        if(parent==child) continue;
        cnt+=dfs(child,node,adj);
    }
    subsize[node]=cnt;
    return cnt;
}

void solve(int node,int parent,vector<vector<int>>& adj,int n){

    long long score=1,sum=0; 
    for(int child:adj[node]){
        if(child==parent) continue;
        sum+=subsize[child];
         score=score*(subsize[child]);
         solve(child,node,adj,n);    
    }
   if(node!=0) ans[node]=score*(n-sum-1);
   else ans[node]=score;
}
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        subsize.assign(n,0);
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[i].push_back(parents[i]);
            adj[parents[i]].push_back(i);
        }
       
       ans.assign(n,0);
        dfs(0,-1,adj);
        solve(0,-1,adj,n);
        
       int cnt=0;
       long long maxsc=INT_MIN; 
       for(int i=0;i<ans.size();i++){
          maxsc=max(maxsc,ans[i]);
       }
       for(int i=0;i<ans.size();i++){
        if(ans[i]==maxsc) cnt++;
       }
       
  return cnt;
    }
};