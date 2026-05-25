class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt=0;
        queue<pair<int,int>>q;
        
        int n=grid.size(),m=grid[0].size();
       vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]>0){
                    q.push({i,j});
                    int sum=0;

                    while(q.size()>0){
                        auto [x,y]=q.front();
                        q.pop();

                        if(vis[x][y]) continue;
                        vis[x][y]=true;
                        sum=(sum+grid[x][y])%k;

                        for(auto [nx,ny]:dir){
                            int newx=nx+x,newy=ny+y;
                            if(newx<n && newy<m && newx>=0 && newy>=0 && !vis[newx][newy] && grid[newx][newy]>0){
                                q.push({newx,newy});
                            }
                        }
                    }

                    if(sum==0) cnt++;
                }
            }
        }

        return cnt;

    }
};