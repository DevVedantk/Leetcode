class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<string>>grid(m,vector<string>(n,"#"));
        
         for(int i=0;i<m;i++){
            grid[i][0]='.';
         }
         for(int i=0;i<n;i++){
            grid[m-1][i]='.';
         }

         vector<string>ans(m);
         for(int i=0;i<m;i++){
            string s="";
            for(int j=0;j<n;j++){
               s+=grid[i][j];
            }
            ans[i]=s;
         }

      return ans;
    }
};