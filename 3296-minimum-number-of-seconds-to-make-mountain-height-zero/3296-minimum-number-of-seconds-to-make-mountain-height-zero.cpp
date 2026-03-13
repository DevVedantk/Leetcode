class Solution {
public:

bool check(long long maxt,int mt,vector<int>&arr){
    long long totalht=0;
    
    for(int i=0;i<arr.size();i++){
        long long ht=0;
        long long limit=2LL*maxt/arr[i];

        while((ht*(ht+1))<=limit) ht++;
        ht--;
        totalht+=ht;
        if(totalht>=mt) return true;
    }

    return totalht>=mt;
}
    long long minNumberOfSeconds(int mt, vector<int>& arr) {
         
         long long lo=0;
         long long hi = 1LL * mt * (mt + 1) / 2 * arr[0];
    long long ans=0;
         while(lo<=hi){
            long long mid=lo+(hi-lo)/2;

            if(check(mid,mt,arr)){
                ans=mid;
                hi=mid-1;
            } else lo=mid+1;
         }

         return ans;
    }
};