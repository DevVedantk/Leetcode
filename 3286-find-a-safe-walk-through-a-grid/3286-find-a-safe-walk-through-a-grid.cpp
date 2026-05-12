class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(),m=grid[0].size();
         vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

         dist[0][0]=grid[0][0];
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};

    pq.push({dist[0][0],0,0});

    while(pq.size()>0){
       auto [dis,x,y]=pq.top();
       pq.pop();

       if(dis>dist[x][y]) continue;

       for(auto [nx,ny]:dir){
        int newx=x+nx;
        int newy=y+ny;

        if(newx>=0 && newy>=0 && newx<n && newy<m && dist[newx][newy]>(dist[x][y]+grid[newx][newy])){
           dist[newx][newy]=dist[x][y]+grid[newx][newy];
           pq.push({dist[newx][newy],newx,newy});
        } 
       }
    }
   
   cout<<  dist[n-1][m-1] << endl;
    if((health-dist[n-1][m-1])>=1) return true;
    return false;
    }
};