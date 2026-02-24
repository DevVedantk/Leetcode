class Solution {
public:
int m,n;
vector<int>dx={1,0,1};
vector<int>dy={0,1,1};
int MOD=1e9+7;
int dp1[101][101];
int dp2[101][101][1900];
int solve(vector<string>& board,int row,int col){
  if(row==m-1 && col==n-1) return 0;
  if(row>=m || col>=n || board[row][col]=='X') return -1e9;
  
  if(dp1[row][col]!=-1) return dp1[row][col];
  int ans=-1e9;
  
  for(int d=0;d<3;d++){
    int val=solve(board,row+dx[d],col+dy[d]);
 if(val!=-1e9)  ans=max(ans,(board[row][col]!='S' ? board[row][col]-'0' : 0)+val);
  }
  return dp1[row][col]=ans;
  
}

int paths(vector<string>& board,int row,int col,int score,int curr){
  if(row==m-1 && col==n-1) return (score==curr);

  if(row>=m || col>=n || board[row][col]=='X') return 0;
   
   if(dp2[row][col][curr]!=-1) return dp2[row][col][curr];
  int ans=0;
  for(int d=0;d<3;d++){
    ans=(ans+paths(board,row+dx[d],col+dy[d],score,curr+(board[row][col]!='S' ? board[row][col]-'0' : 0)))%MOD;
  }

  return dp2[row][col][curr]=ans;
}

vector<int> pathsWithMaxScore(vector<string>& board) {
        m=board.size();
        n=board[0].size();
        board[0][0]='S';
        board[m-1][n-1]='E';
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));

        int ans=solve(board,0,0);
        if(ans==-1e9) ans=0;

        int path=paths(board,0,0,ans,0);
        if(path==0) return {0,0};

        return {ans,path}; 
    }
};