class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0;
        int d=n;
        while(d>0){
            int dig=d%10;
            rev=rev*10+dig;
            d/=10;
        }

        return abs(rev-n);
    }
};