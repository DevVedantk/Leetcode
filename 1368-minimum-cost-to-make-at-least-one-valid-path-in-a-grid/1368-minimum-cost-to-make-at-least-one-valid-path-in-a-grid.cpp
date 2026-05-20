class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;

        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        vector<tuple<int,int,int>>dir={{-1,0,4},{0,-1,2},{1,0,3},{0,1,1}};

        pq.push({0,0,0}); 
        if(n==1 && m==1) return 0;
        

        while(pq.size()>0){
            auto [x,y,dis]=pq.top();
            pq.pop();
            
            if(dis>dist[x][y]) continue;
            for(auto [nx,ny,dir]:dir){
               int newx=x+nx;
               int newy=y+ny;
               int cost=(dir==grid[x][y]) ? 0 :1;

               if(newx>=0 && newy>=0 && newx<n && newy<m && dist[newx][newy]>dis+cost){
                dist[newx][newy]=dis+cost;
                pq.push({newx,newy,dist[newx][newy]});
               }

            }
        }
        return dist[n-1][m-1];

    }
};