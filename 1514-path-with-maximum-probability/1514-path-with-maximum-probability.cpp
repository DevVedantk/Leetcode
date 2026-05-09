class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int st, int end_node) {
           vector<vector<pair<int,double>>>adj(n);

           for(int i=0;i<edges.size();i++){
             int u=edges[i][0],v=edges[i][1];
             double pro=succProb[i];
             adj[u].push_back({v,pro});
             adj[v].push_back({u,pro});
           } 

           vector<double>dist(n,0.0);
           priority_queue<pair<double,int>>pq;
           // probab of start node reach
           pq.push({1.0,st});
           dist[st]=1.0;

           while(pq.size()>0){
            auto [pro,node]=pq.top();
            pq.pop();
            if(pro<dist[node]) continue;
            for(auto [child,wt]:adj[node]){
                if(dist[child]<(wt*pro)){
                    dist[child]=wt*pro;
                    pq.push({dist[child],child});
                }
            }

           }
       
        if(dist[end_node]==0.0) return 0.0;
        return dist[end_node];

    }
};