class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int>prefix(n);
        prefix[0]=(s[0]=='1' ? 1 : 0);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1] + (s[i]=='1' ? 1 : 0);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int ones=prefix[j]-(i==0 ? 0 : prefix[i-1]);
                int zeros=(j-i+1)-ones;

                if((zeros*zeros)>ones){
                    j+=(zeros*zeros-ones-1);
                } else{
                    ans++;
                   int diff=sqrt(ones)-zeros;
                   int nextj=j+diff;
                   
                   if(nextj>=n){
                    ans+=(n-j-1);
                    j=n;
                   } else{
                    ans+=(diff);
                    j=nextj;
                   }

                }
            }
        }

        return ans;

    }
};