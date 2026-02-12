class Solution {
public:
    long long getDescentPeriods(vector<int>& arr) {
         int n=arr.size();
         long long ans=0;
         int i=0,j=1;

         while(j<n){
            if(arr[j-1]==arr[j]+1){
                j++;
            } else{
                int per=j-i;
                 ans+=((long long)per*(per+1))/2;
                 i=j;
                 j++;
            }
         }
          int per=j-i;
          ans+=((long long)per*(per+1))/2;
return ans;
    }
};