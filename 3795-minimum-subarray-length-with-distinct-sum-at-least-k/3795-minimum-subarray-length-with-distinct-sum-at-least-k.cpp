class Solution {
public:
    int minLength(vector<int>& arr, int k) {
        int i=0,j=0;
        map<int,int>mp;

        int n=arr.size();
        int ans=INT_MAX;
        int sum=0;
        while(j<n){
            if(sum>=k){
              ans=min(ans,j-i);
              if(mp[arr[i]]==1){
                  mp.erase(arr[i]);
                sum-=arr[i];
              } else mp[arr[i]]--;
                i++;
            } else{
                if(mp.find(arr[j])==mp.end()){
                    sum+=arr[j];
                    mp[arr[j]]++;
                } else {
                    mp[arr[j]]++;
                }
                    j++;
            }
        }
        // cout << sum << endl;
    // cout << i << endl;
        while(i<n){
             if(sum>=k){
              ans=min(ans,j-i);
              if(mp[arr[i]]==1){
                sum-=arr[i];
                  mp.erase(arr[i]);
              } else mp[arr[i]]--;
                 // cout << i << " " << sum << " " << ans << endl;
                i++;
            } else break;
        }

        cout << ans << endl;
        return ans==INT_MAX ? -1 : ans;
    }
};