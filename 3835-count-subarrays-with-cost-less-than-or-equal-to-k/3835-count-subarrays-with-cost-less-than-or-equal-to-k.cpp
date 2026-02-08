class Solution {
public:
   int n;
    vector<long long> mn, mx;

    void build(vector<int>& arr) {
        n = arr.size();
        mn.assign(2*n, 0);
        mx.assign(2*n, 0);

        // leaves
        for(int i = 0; i < n; i++) {
            mn[n+i] = arr[i];
            mx[n+i] = arr[i];
        }

        // build internal nodes
        for(int i = n-1; i > 0; i--) {
            mn[i] = min(mn[2*i], mn[2*i+1]);
            mx[i] = max(mx[2*i], mx[2*i+1]);
        }
    }

    pair<long long,long long> query(int l, int r) {
        long long minv = LLONG_MAX;
        long long maxv = LLONG_MIN;

        l += n;
        r += n;

        while(l <= r) {
            if(l % 2 == 1) {
                minv = min(minv, mn[l]);
                maxv = max(maxv, mx[l]);
                l++;
            }
            if(r % 2 == 0) {
                minv = min(minv, mn[r]);
                maxv = max(maxv, mx[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }

        return {minv, maxv};
    }

long long countSubarrays(vector<int>& arr, long long k) {
              int n=arr.size();
              

            //   buildt(0,0,n-1,arr);
                      build(arr);
                      
              long long ans=0;
              for(int i=0;i<n;i++){
                int lo=i,hi=n-1;
                 int idx=-1;
                 while(lo<=hi){
                    int mid=(lo+hi)/2;
                    
                    auto [minv, maxv] = query(i, mid);
                    long long maxele=maxv;
                    long long minele=minv;

                    if(((long long)(maxele-minele)*(long long)(mid-i+1))<=k){
                      idx=mid;
                      lo=mid+1;
                    } else hi=mid-1;
                 }
                 if(idx!=-1) ans+=(idx-i+1);
              }

              return ans;
    }
};