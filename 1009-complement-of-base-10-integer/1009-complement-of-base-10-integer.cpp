class Solution {
public:

    int bitwiseComplement(int n) {
        
        int mask=0;
       int dum=n;
     int idx=0;
     int hi=0;
     while(dum>0){
        if(dum%2!=0){
            hi=idx;
        }
        idx++;
        dum>>=1;
     }
     mask=(1<<(hi+1))-1;
     return n^mask;

    //    return ans;
    }
};