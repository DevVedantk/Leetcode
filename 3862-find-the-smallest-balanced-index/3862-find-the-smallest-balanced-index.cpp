class Solution {
public:
    int smallestBalancedIndex(vector<int>& arr) {
     int n=arr.size();
        if(n<=1) return -1;
        vector<long long>pref(n,0);
        // vector<long long>suff(n,0);
        pref[0]=(long long)arr[0];
        for(int i=1;i<n;i++){
             pref[i]=(long long)(pref[i-1] +arr[i]);
        }
        long long maxs=pref[n-1];
        // suff[n-1]=arr[n-1];
        // for(int i=n-2;i>=0;i--) suff[i]=((long long)(suff[i+1]*arr[i]));
        // cout << "hello" << endl;

        int ans=INT_MAX;

        long long p=1;
        for(int i=n-1;i>=0;i--){
            if(i==0){
                 long long sum=0;
                // if(p>=maxs) break;
               if(p > LLONG_MAX / arr[i+1]) break;
                   p*=arr[i+1];
                if(sum==p){
                    ans=min(ans,i);
                }
            } else if(i==n-1){
                long long sum=pref[n-2];
                 if(sum==p){
                    ans=min(ans,i);
                }
            } else{
                long long sum=pref[i-1];
                // if(p>=maxs) break;
           if(p > LLONG_MAX / arr[i+1]) break;
               p*=arr[i+1];
                 if(sum==p){
                    ans=min(ans,i);
                }
            }
        }

        if(ans==INT_MAX) return -1;
        return ans;
    }
};