class Solution {
public:
    int maxProduct(vector<int>& arr) {
     
          int i=0;
          int ans=INT_MIN;
          int prd=1;
          while(i<arr.size()){
              prd=prd*arr[i];
              ans=max(ans,prd);

                if(prd==0){
                  prd=1;
                }
              i++;
          }

         i=arr.size()-1;
        prd=1;
          while(i>=0){
              prd=prd*arr[i];
              ans=max(ans,prd);
                if(prd==0){
                  prd=1;
                }
              i--;
          }

          return ans;
    }
};