class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        vector<vector<int>>ans(n,vector<int>(m));
      int MOD=12345;
       vector<int>arr;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) arr.push_back(grid[i][j]%MOD);
       }
      
      int size=arr.size();
       vector<int>pref(size,1);
       vector<int>suff(size,1);
       
       pref[0]=arr[0];
       suff[size-1]=arr[size-1];

       for(int i=1;i<size;i++){
        pref[i]=(pref[i-1]%MOD*arr[i]%MOD)%MOD;
       }

        for(int i=size-2;i>=0;i--){
        suff[i]=(suff[i+1]%MOD*arr[i]%MOD)%MOD;
       }
       
         int k=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int p1=k-1>=0 ? pref[k-1] : 1;
                int p2=k+1<size ? suff[k+1] : 1;
               ans[i][j]=(p1%MOD*p2%MOD)%MOD;
               k++;
            }
        }

     return ans;

    }
};