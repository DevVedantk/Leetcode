class Solution {
public:
long long dp[18][2][2][2][2];
long long solve(string& R,int idx,bool started,bool finish1,bool finish2,int carry){
     if(idx==R.size()) return (carry==0 && started);
       
       if(dp[idx][started][finish1][finish2][carry]!=-1) return 
       dp[idx][started][finish1][finish2][carry];

     if(finish1 && finish2) return 0;
     long long ans=0;
     if(carry==R[idx]-'0') ans+=solve(R,idx+1,started,1,1,0);

     if(finish1){
        //j not start from 0 because non zero number
        for(int j=1;j<=9;j++){
           int curr=carry+j;
           int newcarry=curr/10;
           curr=curr%10;
           if(curr==R[idx]-'0') ans+=solve(R,idx+1,1,1,finish2,newcarry);
        }
     } 

      if(finish2){
        //j not start from 0 because non zero number
        for(int j=1;j<=9;j++){
           int curr=carry+j;
           int newcarry=curr/10;
           curr=curr%10;
           if(curr==R[idx]-'0') ans+=solve(R,idx+1,1,finish1,1,newcarry);
        }
     }

     if(!finish1 && !finish2){
        for(int j=1;j<=9;j++){
            for(int k=1;k<=9;k++){
           int curr=carry+j+k;
           int newcarry=curr/10;
           curr=curr%10;
           if(curr==R[idx]-'0'){
             ans+=solve(R,idx+1,0,1,finish2,newcarry); 
             ans+=solve(R,idx+1,0,finish1,1,newcarry); 
             ans+=solve(R,idx+1,started,finish1,finish2,newcarry); 
            }
           }
        }
     }

     return dp[idx][started][finish1][finish2][carry]=ans; 

}
    long long countNoZeroPairs(long long n) {
        string R=to_string(n);
        reverse(R.begin(),R.end());
       memset(dp,-1,sizeof(dp));
      return solve(R,0,1,0,0,0);

    }
};