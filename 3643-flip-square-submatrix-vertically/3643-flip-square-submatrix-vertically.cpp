class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
         
         int rowe=x+k-1,cole=y+k-1;

         for(int col=y;col<=cole;col++){
               int i=x,j=rowe;
               while(i<=j){
                swap(grid[i][col],grid[j][col]);
                i++;
                j--;
               }
         }

         return grid;
    }
};