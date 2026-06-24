class Solution {
public:

// #define long long int;

int M;
int MOD=1e9+7;

    int zigZagArrays(int n, int l, int r) {
          int dp[2001][2001][2];
          memset(dp,0,sizeof(dp));
         M=r-l+1;
         for(int prev=1;prev<=M;prev++){
            dp[n][prev][0]=1;
            dp[n][prev][1]=1;
         }



           for(int i=n-1;i>=0;i--){
            vector<long long>pref1(M+1,0);
            vector<long long>pref0(M+1,0);

            for(int prev=1;prev<=M;prev++){
                pref1[prev]=(pref1[prev-1]+dp[i+1][prev][1])%MOD;
                pref0[prev]=(pref0[prev-1]+dp[i+1][prev][0])%MOD;
            }

            for(int prev=1;prev<=M;prev++){

            //      for(int next=prev+1;next<=M;next++){
            //    dp[i][prev][1]=(dp[i][prev][1]+dp[i+1][next][0])%MOD;
            //      }
                 dp[i][prev][1]=(pref0[M]-pref0[prev]+MOD)%MOD;

            //       for(int next=1;next<prev;next++){
            //    dp[i][prev][0]=(dp[i][prev][0]+dp[i+1][next][1])%MOD;
            //    }

               dp[i][prev][0]=pref1[prev-1]%MOD;
            }
           }

          
          long long ans=0;
         for(int start=1;start<=M;start++){
            ans=(ans+dp[1][start][1])%MOD; //increasing
            ans=(ans+dp[1][start][0])%MOD; //increasing
            // ans=(ans+solve(1,start,0,n))%MOD;  // decreasing
         }   

         return ans;


    }
};