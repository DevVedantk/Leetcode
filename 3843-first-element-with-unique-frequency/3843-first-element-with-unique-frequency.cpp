class Solution {
public:
    int firstUniqueFreq(vector<int>& arr) {

        map<int,int>mp;
          int n=arr.size();
        for(int i=0;i<arr.size();i++) mp[arr[i]]++;
        map<int,int>mp2;
        for(auto ele:mp){
            mp2[ele.second]++; 
        }

        // for(auto ele:mp2) cout << ele.first << " " << ele.second << endl;
        
        int ans=-1;
     

        for(int i=0;i<n;i++){
           int freq=mp[arr[i]];
            if(mp2[freq]==1){
                ans=arr[i];
                break;
            }
        }
        return ans;
    }
};