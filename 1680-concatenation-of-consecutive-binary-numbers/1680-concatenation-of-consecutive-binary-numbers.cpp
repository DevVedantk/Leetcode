class Solution {
public:
        int MOD=1e9+7;


    int concatenatedBinary(int n) {
        int ans=0;
        int pow=1;
        for(int i=n;i>=1;i--){
            int x=i;
            while(x>0){
             if(x&1) ans=(ans+pow)%MOD;
             x>>=1;
            pow=(pow*2)%MOD;
            } 
            
          }
        

        return ans;
    }
};