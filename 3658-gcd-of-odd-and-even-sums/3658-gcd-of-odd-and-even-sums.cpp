class Solution {
public:
    int gcdOfOddEvenSums(int n) {
         
         int odd=n*n;
         int s=2*n-1;
         int even=(s*(s+1))/2;
         
         even-=odd;
        //  cout << odd << " " << even << endl;

         return gcd(odd,even);
    }
};