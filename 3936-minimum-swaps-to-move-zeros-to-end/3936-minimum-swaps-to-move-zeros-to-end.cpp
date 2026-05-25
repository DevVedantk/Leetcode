class Solution {
public:
    int minimumSwaps(vector<int>& arr) {
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) cnt++;
        }

        int ans=0;
        int n=arr.size();
        for(int i=n-1;i>=n-cnt;i--){
            if(arr[i]!=0) ans++;
        }

        return ans;
    }
};