class Solution {
public:
    int row,col;
    long long dp[151][200];
    int MOD=1e9+7;
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    long long solve(vector<vector<int>>& mat,int currRow,int currgcd){
        if(currRow>=row){
            return (currgcd==1);
        }
        if(dp[currRow][currgcd]!=-1) return dp[currRow][currgcd];
        long long ans=0;

        for(int j=0;j<col;j++){
            ans=(ans+solve(mat,currRow+1,gcd(currgcd,mat[currRow][j])))%MOD;
        }
        return dp[currRow][currgcd]=ans;
    }
    int countCoprime(vector<vector<int>>& mat) {
         row=mat.size();
         col=mat[0].size();
          memset(dp,-1,sizeof(dp));
        return (int)solve(mat,0,0);
    }
};