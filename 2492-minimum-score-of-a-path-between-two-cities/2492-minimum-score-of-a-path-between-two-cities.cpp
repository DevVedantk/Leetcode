class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

       queue<pair<int,int>>q;
       vector<vector<pair<int,int>>>adj(n+1);

       for(int i=0;i<roads.size();i++){
        int a=roads[i][0],b=roads[i][1],d=roads[i][2];
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
       }
 
       int ans=INT_MAX;
       
       vector<bool>vis(n+1,false);

       q.push({1,INT_MAX});

       while(q.size()>0){
        auto p=q.front();
        q.pop();
        int node=p.first;
        int d=p.second;
        ans=min(ans,d);

        vis[node]=true;

        for(auto ele:adj[node]){
            if(vis[ele.first]==false){
                q.push({ele.first,ele.second});
            } 
        }
       }

       return ans;


    }
};