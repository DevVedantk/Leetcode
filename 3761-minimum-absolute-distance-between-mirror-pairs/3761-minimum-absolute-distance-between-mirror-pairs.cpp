class Solution {
public:
    int revint(int n){
      int ans=0;
        while(n){
          int lastdig=n%10;
            n/=10;
            ans=10*ans+lastdig;
        }
        return ans;
        
    }
    int minMirrorPairDistance(vector<int>& arr) {
         map<int,vector<int>>org;
        for(int i=0;i<arr.size();i++){
            org[arr[i]].push_back(i);
        }
        int ans=1e9;

   int n=arr.size();
        for(int i=0;i<n;i++){

            int rev=revint(arr[i]);
            auto &v = org[rev];
        
           auto it = lower_bound(v.begin(), v.end(),i);
          if (it != v.end() && *it == i) {
    it++;     
}
          if(it!=v.end())  ans=min(ans,abs(*it-i));
            
        }
        return ans==1e9 ? -1 : ans;
        
    }
};