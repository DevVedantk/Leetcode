class Solution {
public:
vector<int>subtreeSize;
int dfs(int node,int parent,vector<vector<int>>& adj){
    int cnt=1;
    for(int child:adj[node]){
        if(child==parent) continue;
        cnt+=dfs(child,node,adj);
    }
    subtreeSize[node]=cnt-1;
    return cnt;
}
    int countGoodNodes(vector<vector<int>>& edges) {
        
        int n=edges.size()+1;
       vector<vector<int>>adj(n);
       subtreeSize.assign(n,0);
       
       for(int i=0;i<edges.size();i++){
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);
       }
       
       dfs(0,-1,adj);
       queue<pair<int,int>>q;
       q.push({0,-1});
       int cnt=0;
       while(q.size()>0){
          int size=q.size();
          for(int i=0;i<size;i++){
            bool flag=true;
             auto [node,parent]=q.front();
             q.pop();
              
              int fz=-1;
             for(int child:adj[node]){
                if(child==parent) continue;
                if(fz==-1) fz=subtreeSize[child];
                else if(fz!=subtreeSize[child]){
                    flag=false;
                }
                q.push({child,node});
             }
             if(flag) cnt++;
          }

       }
       return cnt;
    }
};