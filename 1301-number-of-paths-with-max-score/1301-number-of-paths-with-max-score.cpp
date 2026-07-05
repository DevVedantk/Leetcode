class Solution {
public:
int MOD=1e9+7;
int dp2[101][101][1801];

int dp1[101][101];
  int solve(int row,int col,vector<string>&board){
      if(board[row][col]=='S'){
        return 0;
      }  

       int n=board.size();
      if(row>=n || col>=n) return INT_MIN;
      if(dp1[row][col]!=-1) return dp1[row][col];


      int ans=INT_MIN;

      if(board[row][col]=='E'){
        if(row+1<n && board[row+1][col]!='X') ans=max(ans,solve(row+1,col,board));
        if(col+1<n && board[row][col+1]!='X') ans=max(ans,solve(row,col+1,board));
        if(col+1<n && row+1<n && board[row+1][col+1]!='X') ans=max(ans,solve(row+1,col+1,board));
      } else{
        if(row+1<n && board[row+1][col]!='X') ans=max(ans,board[row][col]-'0'+solve(row+1,col,board));
        if(col+1<n && board[row][col+1]!='X') ans=max(ans,board[row][col]-'0'+solve(row,col+1,board));
        if(col+1<n && row+1<n && board[row+1][col+1]!='X') ans=max(ans,board[row][col]-'0'+solve(row+1,col+1,board));
      }

      return dp1[row][col]=ans;

  }

  int solve2(int row,int col,int target,int sum,vector<string>&board){
          
          if(board[row][col]=='S'){
            return (sum==target);
          }
  
               
       int n=board.size();
      if(row>=n || col>=n) return 0;
          if(dp2[row][col][sum]!=-1) return dp2[row][col][sum]; 

          int ans=0;

        if(board[row][col]=='E'){
        if(row+1<n && board[row+1][col]!='X') ans=(ans+solve2(row+1,col,target,sum,board))%MOD;
        if(col+1<n && board[row][col+1]!='X') ans=(ans+solve2(row,col+1,target,sum,board))%MOD;
        if(col+1<n && row+1<n && board[row+1][col+1]!='X') ans=(ans+solve2(row+1,col+1,target,sum,board))%MOD;
      } else{
        if(row+1<n && board[row+1][col]!='X') ans=(ans+solve2(row+1,col,target,sum+board[row][col]-'0',board))%MOD;
        if(col+1<n && board[row][col+1]!='X') ans=(ans+solve2(row,col+1,target,sum+board[row][col]-'0',board))%MOD;
        if(col+1<n && row+1<n && board[row+1][col+1]!='X') ans=(ans+solve2(row+1,col+1,target,sum+board[row][col]-'0',board))%MOD;
      }

      return dp2[row][col][sum]=ans;

  }


    vector<int> pathsWithMaxScore(vector<string>& board) {
          
        memset(dp1,-1,sizeof(dp1));
        
          int sum=solve(0,0,board);
        //   cout << sum << " " << INT_MIN << endl;
          if(sum<0) return {0,0};
          
        memset(dp2,-1,sizeof(dp2));
          int paths=solve2(0,0,sum,0,board);

          return {sum,paths};
    }
};