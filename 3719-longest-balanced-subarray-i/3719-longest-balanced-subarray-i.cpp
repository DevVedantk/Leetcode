class Solution {
public:
    int longestBalanced(vector<int>& arr) {
         int ans=0;
        for(int i=0;i<arr.size();i++){
        set<int>even;
        set<int>odd;
            for(int j=i;j<arr.size();j++){
                 if(arr[j]%2==0) even.insert(arr[j]);
                 else odd.insert(arr[j]);
                 if(even.size()==odd.size()) ans=max(ans,j-i+1);
            }
        } 

        return ans;
    }
};