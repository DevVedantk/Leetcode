class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1],wt=edges[i][2];
            adj[u].push_back({v,wt+1});
            adj[v].push_back({u,wt+1});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);

        dist[0]=0;
        pq.push({0,0});

        while(pq.size()>0){
           auto [dis,node]=pq.top();
           pq.pop();
           if(dis>dist[node]) continue;

           for(auto [child,wt]:adj[node]){
            if(dist[child]>dis+wt){
                dist[child]=dis+wt;
                pq.push({dist[child],child});
            }
           }
        }

        int cnt=0;

        for(int ele:dist) if(ele<=maxMoves) cnt++;

        for(int i=0;i<edges.size();i++){
             int a=edges[i][0],b=edges[i][1],wt=edges[i][2];
             int fromA=max(0,maxMoves-dist[a]);
             int fromB=max(0,maxMoves-dist[b]);
             cnt=cnt+min(wt,fromA+fromB);
        }

        return cnt;
    }
};