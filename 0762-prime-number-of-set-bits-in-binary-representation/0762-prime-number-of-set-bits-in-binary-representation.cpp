class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int>check={2,3,5,7,11,13,17,19};
        
        int ans=0;
        for(int i=left;i<=right;i++){
           int n=i;
           int cnt=0;
           while(n>0){
            if(n%2!=0) cnt++;
            n=n>>1;
           }
           for(int i=0;i<8;i++) if(check[i]==cnt) ans++;
        } 
        return ans;
    }
};