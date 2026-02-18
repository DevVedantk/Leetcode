class Solution {
public:
    long long maxProduct(vector<int>& arr) {
   int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<0) arr[i]=arr[i]*-1;
        }
        sort(arr.begin(),arr.end());

        return (long long)1e5*(arr[n-1])*arr[n-2];
        
    }
};