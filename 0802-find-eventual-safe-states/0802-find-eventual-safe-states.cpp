class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>deg(n);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int ele:graph[i]){
                adj[ele].push_back(i);
                deg[i]++;
            }
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
    sort(res.begin(),res.end());
   return res;
    }
};