class Solution {
public:
bool check(vector<int>& arr,int k){
    vector<int>len(arr.size());
    int i=1,cnt=1;
        len[0]=1;
    while(i<arr.size()){
        if(arr[i-1]<arr[i]) cnt++;
        else cnt=1;
        len[i]=cnt;
        i++;
    }

    for(int i=0;i<len.size()-k;i++){
        if(len[i]>=k && len[i+k]>=k) return true;
    }
    return false;
}
    int maxIncreasingSubarrays(vector<int>& arr) {
       int l=1,h=arr.size();
     int ans=0;
       while(l<=h){
        int mid=(l+h)/2;
        if(check(arr,mid)){
            ans=mid;
            l=mid+1;
        } else h=mid-1;
       }

       return ans; 
    }
};