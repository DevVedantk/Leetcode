class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& arr, int k) {
     
     int i=1;
     int cnt=1;
     
     vector<int>len(arr.size(),0);
     len[0]=1;
     while(i<arr.size()){
        if(arr[i]>arr[i-1]) cnt++;
        else cnt=1; 
        len[i]=cnt;
        i++;
     }

     for(int i=0;i<len.size()-k;i++) if(len[i]>=k && len[i+k]>=k) return true;
    return false;
    }
};