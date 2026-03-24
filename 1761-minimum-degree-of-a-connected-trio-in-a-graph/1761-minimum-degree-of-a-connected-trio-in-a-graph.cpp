class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
          
          vector<int>out(n+1,0);
         vector<vector<int>>adj(n+1);
         vector<vector<bool>> mat(n+1, vector<bool>(n+1,false));
         for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            out[a]++;
            out[b]++;
            mat[a][b]=true;
            mat[b][a]=true;

         }
         
    int ans=INT_MAX;

       for(int i=1;i<=n;i++){
         vector<int>dist(n+1,-1);
         vector<int>par(n+1,-1);

        queue<int>q;
        q.push(i);
        dist[i]=0; 

        while(q.size()>0){
            int node=q.front();
            q.pop();

            for(int child:adj[node]){
                if(dist[child]==-1){
                    dist[child]=dist[node]+1;
                    par[child]=node;
                    q.push(child);
                } else if(par[node]!=child){
                   int len=dist[child]+dist[node]+1;
                    if(len==3){
                        int a = par[node];
                      int b = node;
                       int c = child; 
                    if(a==-1 || !mat[a][c]) continue;

                    if(a<b && b<c){
                        ans=min(ans,out[a]+out[b]+out[c]-6);
                    }
                    }
                }
            }
        }
       }
    
        if(ans==INT_MAX) return -1;
       return ans;
    }
};