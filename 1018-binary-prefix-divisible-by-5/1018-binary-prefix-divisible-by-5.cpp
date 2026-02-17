class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& arr) {
      int n=arr.size();
      vector<bool> ans(n,false);
      int num=arr[0];
      if(arr[0]==0) ans[0]=true;
      for(int i=1;i<arr.size();i++){
        num=num*2;
        num=(num+arr[i])%5;
        if(num==0) ans[i]=true;
      }
      return ans;
        
    }
};