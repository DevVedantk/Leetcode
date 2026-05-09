class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>>adj(n+1);

        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        dist[k]=0;
        //dist , node
        pq.push({0,k});
        
        while(pq.size()>0){
            auto [dis,node]=pq.top();
            pq.pop();

            if(dist[node]>dis) continue;

            for(auto [child,wt]:adj[node]){
                if(dist[child]>wt+dis){
                    dist[child]=wt+dis;
                    pq.push({dist[child],child});
                }
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }

        return ans;
    }
};