class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].insert(edges[i][0]);

        }

        vector<vector<int>>ans(n);
         
         for(int i=0;i<n;i++){
            queue<int>q;
            q.push(i);
            set<int>st;
             vector<int> vis(n, 0); 
             vis[i]=1;
           
           while(q.size()>0){
             int node=q.front();
             q.pop();

            for(int child:adj[node]){
                if(vis[child]==0){
                    vis[child]=1;
                st.insert(child);
                q.push(child);
                }
            }
           }

           for(int ele:st) {
            ans[i].push_back(ele);
           }

         }

        return ans;
    }
};