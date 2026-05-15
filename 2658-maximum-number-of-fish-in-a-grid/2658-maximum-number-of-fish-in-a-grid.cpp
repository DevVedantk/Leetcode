class Solution {
public:
vector<vector<bool>>vis;

int get_ans(int r,int c,vector<vector<int>>& grid){
     queue<pair<int,int>>q;
     vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};

     q.push({r,c});
     
     int fish=0;
     while(q.size()>0){
      auto [x,y]=q.front();
      q.pop();
      if(vis[x][y]) continue;
       vis[x][y]=true;
       fish+=grid[x][y];

       for(auto [nx,ny]:dir){
        int newx=nx+x;
        int newy=ny+y;

        if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && !vis[newx][newy] && grid[newx][newy]>0){
            q.push({newx,newy});
        }
       }
     }

     return fish;
}
    int findMaxFish(vector<vector<int>>& grid) {
        
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        vis.assign(n,vector<bool>(m,false));

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0 && !vis[i][j]){
                  ans=max(ans,get_ans(i,j,grid));

                }
            }
        }
     return ans;
    }
};