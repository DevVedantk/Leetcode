class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        vector<pair<int,int>> dir = {
            {1,0},{0,1},{-1,0},{0,-1}
        };

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // store best (minimum) obstacle used so far
        vector<vector<int>> obs(m, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, tuple<int,int,int>>,
            vector<pair<int, tuple<int,int,int>>>,
            greater<pair<int, tuple<int,int,int>>>
        > pq;

        pq.push({0,{0,0,0}});

        dist[0][0] = 0;
        obs[0][0] = 0;

        while(!pq.empty()) {

            auto [dis,t] = pq.top();
            pq.pop();

            auto [x,y,used] = t;

            if(x == m-1 && y == n-1)
                return dis;

            // stale state
            if(used > obs[x][y] && dis > dist[x][y])
                continue;

            for(auto [dx,dy] : dir) {

                int nx = x + dx;
                int ny = y + dy;

                if(nx>=0 && ny>=0 && nx<m && ny<n) {

                    int newUsed = used + grid[nx][ny];

                    if(newUsed > k)
                        continue;

                    int newDist = dis + 1;

                    // IMPORTANT CHANGE
                    if(newDist < dist[nx][ny] || newUsed < obs[nx][ny]) {

                        dist[nx][ny] = min(dist[nx][ny], newDist);
                        obs[nx][ny] = min(obs[nx][ny], newUsed);

                        pq.push({
                            newDist,
                            {nx, ny, newUsed}
                        });
                    }
                }
            }
        }
        

        return -1;
    }
};