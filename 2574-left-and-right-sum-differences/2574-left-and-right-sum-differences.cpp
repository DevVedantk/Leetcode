class Solution {
public:
    vector<int> leftRightDifference(vector<int>& arr) {
         vector<int>left(arr.size());
         vector<int>right(arr.size());
          
          int n=arr.size();
          if(n==1) return {0};

        left[0]=0;
        left[1]=arr[0];

        for(int i=2;i<arr.size();i++) left[i]=left[i-1]+arr[i-1];
        
    
        right[n-1]=0;
        right[n-2]=arr[n-1];
          for(int i=n-3;i>=0;i--) right[i]=right[i+1]+arr[i+1];
     
     vector<int>ans(n);
    
     for(int i=0;i<n;i++){
        ans[i]=abs(left[i]-right[i]);
     }

     return ans;
    }
};