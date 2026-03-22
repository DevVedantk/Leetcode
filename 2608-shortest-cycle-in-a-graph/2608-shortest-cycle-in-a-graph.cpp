class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
         int ans=INT_MAX;
         vector<vector<int>>adj(n);
         for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
         }


         for(int i=0;i<n;i++){
            queue<int>q;
            vector<int>parent(n,-1);
            vector<int>dis(n,-1);
            q.push(i);

            dis[i]=0;
            
            while(q.size()>0){
                int node=q.front();
                q.pop();

                for(int child:adj[node]){
                    if(dis[child]==-1){
                        dis[child]=dis[node]+1;
                        q.push(child);
                        parent[child]=node;

                    } else if(parent[node]!=child){
                        //cycle found
                        ans=min(ans,dis[node]+dis[child]+1);
                    }
                }
            }
         }

         return ans==INT_MAX ? -1 : ans;

    }
};