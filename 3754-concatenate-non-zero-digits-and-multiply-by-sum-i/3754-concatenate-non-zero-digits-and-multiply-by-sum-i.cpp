class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        int num=0;

        while(n>0){
            int dig=n%10;
            sum+=dig;
            if(dig>0){
                num=num*10+dig;
            }
            n/=10;
        }
        long long rev=0;

        while(num>0){
           int dig=num%10;
           num/=10;
           rev=rev*10+dig; 
        }



        return rev*sum;
    }
};