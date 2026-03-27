class Solution {
public:
    bool areSimilar(vector<vector<int>>& org, int k) {
        vector<vector<int>>mat=org;
        int flip=k%mat[0].size();
         
        for(int i=0;i<k;i++){
             
             for(int a=0;a<mat.size();a++){
                if(a%2==0){
                    for(int col=0;col<mat[0].size()-1;col++){
                        swap(mat[a][col],mat[a][col+1]);
                    }
                } else{
                   for(int col=mat[0].size()-1;col>=1;col--){
                        swap(mat[a][col],mat[a][col-1]);
                    }  
                }   

             }
        }

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]!=org[i][j]) return false;
            }
        }  

        return true;


    }
};