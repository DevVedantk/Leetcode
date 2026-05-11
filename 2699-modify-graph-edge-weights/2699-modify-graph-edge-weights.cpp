class Solution {
public:

    long long dijkstra(int n,
                       vector<vector<int>>& edges,
                       int source,
                       int destination) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges){

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if(wt == -1) continue;

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[source] = 0;

        pq.push({0, source});

        while(!pq.empty()){

            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto [child, wt] : adj[node]){

                if(dist[child] > d + wt){

                    dist[child] = d + wt;

                    pq.push({dist[child], child});
                }
            }
        }

        return dist[destination];
    }

    vector<vector<int>> modifiedGraphEdges(int n,
                                           vector<vector<int>>& edges,
                                           int source,
                                           int destination,
                                           int target) {

        long long INF = 2e9;

        // all -1 = INF
        bool c=false;
        for(auto &e : edges){
            if(e[2]==-1) c=true;
            if(e[2] == -1)
                e[2] = INF;
        }
       

        long long maxDist =
            dijkstra(n, edges, source, destination);
           
           if(maxDist==target && !c) return edges;
        // fixed smaller path already exists
        if(maxDist < target)
            return {};

        // restore all INF back to -1
        for(auto &e : edges){

            if(e[2] == INF)
                e[2] = -1;
        }

        // try greedily
        bool done = false;

        for(auto &e : edges){

            if(e[2] != -1) continue;

            e[2] = 1;

            long long dist =
                dijkstra(n, edges, source, destination);

            if(dist <= target){

                e[2] += (target - dist);

                done = true;

                break;
            }
        }


        if(!done) return {};

        // remaining -1 => INF
        for(auto &e : edges){

            if(e[2] == -1)
                e[2] = INF;
        }

        long long finalDist =
            dijkstra(n, edges, source, destination);

        if(finalDist != target)
            return {};

        return edges;
    }
};