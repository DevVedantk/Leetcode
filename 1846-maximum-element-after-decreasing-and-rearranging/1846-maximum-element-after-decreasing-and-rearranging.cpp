class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
         
         sort(arr.begin(),arr.end());
        
        if(arr[0]>1) arr[0]=1;
        
         for(int i=0;i<arr.size()-1;i++){
            if(abs(arr[i]-arr[i+1])>1){
                arr[i+1]=arr[i]+1;
            }
         }

         int ans=0;
         for(int ele:arr) ans=max(ans,ele);

         return ans;
    }
};