class Solution {
public:
    int getMinDistance(vector<int>& arr, int target, int start) {
        int ans=INT_MAX;
           for(int i=0;i<arr.size();i++){
            if(arr[i]==target) ans=min(ans,abs(i-start));
           }

           return ans;
    }
};