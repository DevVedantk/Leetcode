class Solution {
public:
    vector<int> resultArray(vector<int>& arr) {
        vector<int>arr1,arr2,ans;

         arr1.push_back(arr[0]);
         arr2.push_back(arr[1]);
         
         for(int i=2;i<arr.size();i++){
            if(arr1[arr1.size()-1]>arr2[arr2.size()-1]) arr1.push_back(arr[i]);
            else arr2.push_back(arr[i]);
         }
          for(int i=0;i<arr1.size();i++) ans.push_back(arr1[i]);
          for(int i=0;i<arr2.size();i++) ans.push_back(arr2[i]);
          
         return ans;
    }
};