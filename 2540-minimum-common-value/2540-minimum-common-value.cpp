class Solution {
public:
    int getCommon(vector<int>& arr1, vector<int>& arr2) {
         int l=0,r=0;
         while(l<arr1.size() && r<arr2.size()){
            if( arr1[l]>arr2[r]) r++;
            else if( arr1[l]<arr2[r]) l++;
            else if(arr1[l]==arr2[r]) return arr1[l];
         }

         return -1;
    }
};