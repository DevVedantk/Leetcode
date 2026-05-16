class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
       vector<vector<bool>>vis(n,vector<bool>(m,false));
      vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
      queue<pair<int,int>>q;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((j==0 || j==m-1) && board[i][j]=='O') q.push({i,j});
            if((i==0 || i==n-1) && board[i][j]=='O') q.push({i,j});
        }
      }

      while(q.size()>0){
        auto [nx,ny]=q.front();
        q.pop();

        if(vis[nx][ny]) continue;

        vis[nx][ny]=true;

        for(auto [x,y]:dir){
            int newx=x+nx;
            int newy=y+ny;

  if(newx>=0 && newy>=0 && newx<n && newy<m && board[newx][newy]=='O' && !vis[newx][newy]){
             q.push({newx,newy});
            }
        }
      }


      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && board[i][j]=='O') board[i][j]='X';
        }
      }

        
    }
};