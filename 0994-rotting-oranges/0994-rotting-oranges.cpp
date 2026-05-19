class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};

        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        int n=grid.size();
        int m=grid[0].size();

        int minu=0;

        while(q.size()>0){
            int size=q.size();

            for(int i=0;i<size;i++){
                 auto [x,y]=q.front();
                 q.pop();

                 for(int j=0;j<4;j++){
                    int newx=x+dir[j].first;
                    int newy=y+dir[j].second;

                    if(newx<n && newy<m && newx>=0 && newy>=0 && grid[newx][newy]==1){
                        grid[newx][newy]=2;
                        q.push({newx,newy});
                        fresh--;
                    }
                 }
            }

            minu++;
        }

   return fresh==0 ? (minu-1) : -1;



    }
};