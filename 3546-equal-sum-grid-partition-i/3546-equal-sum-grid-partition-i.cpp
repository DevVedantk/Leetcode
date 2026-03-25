class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int m=grid.size();
        vector<vector<long long>>sum(m+1,vector<long long>(n+1,0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                sum[i][j]=grid[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            }
        }
        
        //vertical cuts
        for(int col=0;col<n-1;col++){
            int a1=0,b1=0,c1=m-1,d1=col;
            long long sum1=sum[c1+1][d1+1]-sum[c1+1][b1]-sum[a1][d1+1]+sum[a1][b1];

            int a2=0,b2=col+1,c2=m-1,d2=n-1;
           long long sum2=sum[c2+1][d2+1]-sum[c2+1][b2]-sum[a2][d2+1]+sum[a2][b2]; 
         if(sum1==sum2) return true; 
        }


          //horizontal cuts
        for(int row=0;row<m-1;row++){
            int a1=0,b1=0,c1=row,d1=n-1;
            long long sum1=sum[c1+1][d1+1]-sum[c1+1][b1]-sum[a1][d1+1]+sum[a1][b1];

            int a2=row+1,b2=0,c2=m-1,d2=n-1;
       long long sum2=sum[c2+1][d2+1]-sum[c2+1][b2]-sum[a2][d2+1]+sum[a2][b2]; 
         if(sum1==sum2) return true; 
        }

        return false;
    }
};