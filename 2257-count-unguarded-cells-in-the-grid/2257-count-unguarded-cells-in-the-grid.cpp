class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
         vector<vector<int>>arr(m,vector<int>(n,0));
         
         //gaurd =-1
         //wall = 1
         for(int i=0;i<g.size();i++){
            int r=g[i][0],c=g[i][1];
            arr[r][c]=-1;
         } 

          for(int i=0;i<w.size();i++){
            int r=w[i][0],c=w[i][1];
            arr[r][c]=-1;
         }

         for(int i=0;i<g.size();i++){

            int r=g[i][0],c=g[i][1];
            

            int nr=r-1;
            while(nr>=0 && arr[nr][c]!=-1){
                arr[nr][c]=1;
                nr--;
            } 
            
              nr=r+1;
            //   c=g[i][1];

              while(nr<m && arr[nr][c]!=-1){
                arr[nr][c]=1;
                nr++;
            } 

           
             int nc=c-1;

              while(nc>=0 && arr[r][nc]!=-1){
                arr[r][nc]=1;
                nc--;
            } 

           
              nc=c+1;

              while(nc<n && arr[r][nc]!=-1){
                arr[r][nc]=1;
                nc++;
            } 
         }
      
         int cnt=0;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==0) cnt++;
            }
         } 
         return cnt;

    }
};