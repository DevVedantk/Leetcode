class Solution {
public:

bool check(vector<vector<int>>&mat,vector<vector<int>>&tar){
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            if(tar[i][j]!=mat[i][j]) return false;
        }
    }
    return true;
}
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
           
           vector<vector<int>>temp=mat;
          for(int i=1;i<=4;i++){
            //clockwise rotation 
             if(check(mat,target)) return true;
               
               int col2=0;
              for(int row1=0;row1<mat.size();row1++){
                    int col1=0;
                   for(int row2=mat.size()-1;row2>=0;row2--){
                       temp[row1][col1]=mat[row2][col2];
                       col1++;
                   }
                   col2++;
              }

              mat=temp;
          }

          for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++) cout << mat[i][j] << " ";
            cout << endl;
          }
      return false;
    }
};