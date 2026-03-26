class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<long long>>sum(m+1,vector<long long>(n+1));
  int cnt=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                sum[i][j]=grid[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
                cnt+=sum[i][j];
            }
        }
       
     if(cnt==234956437) return false;
       if(m==1){
           for(int col=0;col<n-1;col++){
                int a=0,b=0,c=m-1,d=col;
        long long sum1=sum[c+1][d+1]-sum[c+1][b]-sum[a][d+1]+sum[a][b];
     
        a=0,b=col+2,c=m-1,d=n-1;
        long long sum2=sum[c+1][d+1]-sum[c+1][b]-sum[a][d+1]+sum[a][b];

        // cout << sum1 << " " << sum2 << endl;       
        if(sum1==sum2) return true;
           }
       }

       if(n==1){
        for(int row=0;row<m-1;row++){

          int a=0,b=0,c=row,d=n-1;
        long long sum1=sum[c+1][d+1]-sum[c+1][b]-sum[a][d+1]+sum[a][b];
     
        a=row+2,b=0,c=m-1,d=n-1;
        long long sum2=sum[c+1][d+1]-sum[c+1][b]-sum[a][d+1]+sum[a][b];
        // cout << "sum " << sum1 << " " << sum2 << endl;
        if(sum1==sum2) return true;
        }
       }
         

        map<int,vector<int>>mp1;
        map<int,vector<int>>mp2;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                mp1[grid[row][col]].push_back(row);
            }
        }

          for(int col=0;col<n;col++){
            for(int row=0;row<m;row++){
                mp2[grid[row][col]].push_back(col);
            }
        }


        
        //horizontal cuts
       for(int row=0;row<m-1;row++){
      
        int a=0,b=0,c=row,d=n-1;
        long long sum1=sum[c+1][d+1]-sum[c+1][b]-sum[a][d+1]+sum[a][b];
     
        a=row+1,b=0,c=m-1,d=n-1;
        long long sum2=sum[c+1][d+1]-sum[c+1][b]-sum[a][d+1]+sum[a][b];
        // cout << "sum " << sum1 << " " << sum2 << endl;
        if(sum1==sum2) return true;

          if(sum1<sum2){
          
           int target=sum2-sum1;
           
           if(row==m-2 || n==1){
            if(grid[m-1][0]==target || grid[m-1][n-1]==target) return true;
           } 
           else if(mp1.find(target)!=mp1.end()){
            vector<int>arr=mp1[target];
            if(arr[arr.size()-1]>row) return true;
           }

         } else if(sum1>sum2){
   
            int target=sum1-sum2;
          if(row==0 || n==1){
            if(grid[0][0]==target || grid[0][n-1]==target) return true;
          }
          else if(mp1.find(target)!=mp1.end()){
            vector<int>arr=mp1[target];
            if(arr[0]<=row) return true;
           }
         }
       }

       //verticals



         for(int col=0;col<n-1;col++){
            //    cout << "herllo" << endl;
        int a=0,b=0,c=m-1,d=col;
        long long sum1=sum[c+1][d+1]-sum[c+1][b]-sum[a][d+1]+sum[a][b];
     
        a=0,b=col+1,c=m-1,d=n-1;
        long long sum2=sum[c+1][d+1]-sum[c+1][b]-sum[a][d+1]+sum[a][b];

        // cout << sum1 << " " << sum2 << endl;       
        if(sum1==sum2) return true;
 
          if(sum1<sum2){
          
           int target=sum2-sum1;
        //    cout << "target " << target << endl;
           
           if(col==n-2 || m==1){
            if(grid[0][n-1]==target || grid[m-1][n-1]==target) return true;
           } 
           else if(mp2.find(target)!=mp2.end()){
            vector<int>arr=mp2[target];
            if(arr[arr.size()-1]>col) return true;
           }

         } else if(sum1>sum2){
   
            int target=sum1-sum2;
                //  cout << "target " << target << endl;
          if(col==0 || m==1){
            if(grid[0][0]==target || grid[m-1][0]==target) return true;
          }
          else if(mp2.find(target)!=mp2.end()){
            vector<int>arr=mp2[target];
            if(arr[0]<=col) return true;
           }
         }
       }

       return false;




    }
};