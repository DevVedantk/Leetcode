class Solution {
public:
    long long minMoves(vector<int>& arr) {
        long long sum=0;
        int n=arr.size();
        int idx=-1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(arr[i]<0) idx=i;
        }
        if(sum<0) return -1;
        if(idx==-1) return 0;
         
         long long ans=0;
         int i=idx-1,j=idx+1;
         if(j==n) j=0;
         if(i==-1) i=n-1;
        
           int cnt=0;
         int require=abs(arr[idx]);
         while(arr[idx]<0){
            if(i<0 && j>=n) break;
            if(i>=0 && arr[i]>=require){
                arr[idx]+=require;
                int dist = abs(idx - i);
                    dist = min(dist, n - dist);
                      ans += 1LL * dist * require;
                  i--;
                  cnt++;
            } else if(i>=0 && arr[i]<require){
                arr[idx]+=arr[i];
                require-=arr[i];
                int dist = abs(idx - i);
                    dist = min(dist, n - dist);
                      ans += 1LL * dist * arr[i];
                i--; 
                cnt++;
            }
            // cout  << arr[idx] << " " ; 

           if(arr[idx]>=0) break;
              if(j<n && arr[j]>=require){
                arr[idx]+=require;
                //  int minidx=min(idx+j,(n+j-1)%n);
                 int dist = abs(idx - j);
                    dist = min(dist, n - dist);
                      ans += 1LL * dist * require;
                // ans+=(abs(idx-minidx)*require);
                cnt++;
                j++;
            } else if(j<n && arr[j]<require){
                arr[idx]+=arr[j];
                require-=arr[j];
                int dist = abs(idx - j);
                    dist = min(dist, n - dist);
                      ans += 1LL * dist * arr[j];
                j++; 
                cnt++;
            }
            if(j>=n && cnt<n) j=0;
            if(i<0 && cnt<n) i=n-1;  
         }

         return ans;

    }
};