class Solution {
public:
    bool isGood(vector<int>& arr) {
          sort(arr.begin(),arr.end());
          int mx=INT_MIN,mn=INT_MAX;
          
          int n=arr.size();
        if(n<2) return false;
        int sum=0;
          if(arr[n-1]!=arr[n-2]) return false;
          
           mx=max({mx,arr[n-1],arr[n-2]});

           mn=min({mn,arr[n-1],arr[n-2]});

          for(int i=n-3;i>=0;i--){
            mx=max(mx,arr[i]);
            mn=min(mn,arr[i]);
             if(arr[i]==arr[i+1]) return false;
          }
          cout << mx << " " << mn << endl;
          if(mx!=n-1 || mn!=1) return false;
          return true;
    }
};