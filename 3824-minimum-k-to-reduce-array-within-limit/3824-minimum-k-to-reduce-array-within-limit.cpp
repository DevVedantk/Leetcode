class Solution {
public:    
    bool check(vector<int>&arr,long long k){
        long long op=0;

        for(int i=0;i<arr.size();i++){
            int step=(arr[i]+k-1)/k;
            // cout << arr[i] << " " <<k <<" "<<step << endl;
            op+=step;
        }
    // cout <<k << " " << op << endl;
        return op<=(k*k);
        
    }
    int minimumK(vector<int>& arr) {
        long long l=1,hi=1e9;
        int ans=0;
        while(l<=hi){
            long long mid=(l+hi)/2;
            if(check(arr,mid)){
                ans=mid;
                hi=mid-1;
            } else l=mid+1;
        }
 cout << ans << endl;
        return ans;
    }
};