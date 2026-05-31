class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
         sort(arr.begin(),arr.end());
         long long ms=mass;

         for(int i=0;i<arr.size();i++){
            if(arr[i]>ms) return false;
            ms+=arr[i];
         }

         return true;
    }
};