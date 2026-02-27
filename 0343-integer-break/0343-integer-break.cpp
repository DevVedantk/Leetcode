class Solution {
public:

int maxproduct(int n,int curr_product,int k,int deg){
     if(n==0 && k>=2) return curr_product;
      if(n<0 || deg>n) return 0;
    
    // int ans=INT_MIN;
   
   int breakit=0,notbreak=0;
    if(n>=deg){
      breakit=maxproduct(n-deg,curr_product*deg,k+1,deg);
    }
   notbreak=maxproduct(n,curr_product,k,deg+1);

    return max(breakit,notbreak);

}
    int integerBreak(int n) {
        
        return maxproduct(n,1,0,1);
    }
};