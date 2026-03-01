class Solution {
public:
int getmsb(int n){
    int res=-1;
    for(int i=31;i>=0;i--){
        if(n&(1<<i)) return i;
    }

    return res;
}
    int minimumOR(vector<vector<int>>& grid) {
          int n=grid.size(); 
          int m=grid[0].size(); 
         
         vector<int>bit;
         while(true){
            int off=-1;
         for(int i=0;i<n;i++){
            int minmsb=INT_MAX;
            for(int j=0;j<m;j++){
                int msb=getmsb(grid[i][j]);
                minmsb=min(minmsb,msb);
             }
           off=max(off,minmsb);
         }
     if(off==-1) break;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 int msb=getmsb(grid[i][j]);
                 if(msb==off) grid[i][j]^=(1<<msb);
            }
         }
         bit.push_back(off);
         }
    int ans=0;
         for(int ele:bit){
          ans=ans| (1<<ele);
         }
         return ans;



    }
};