class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
         int ans=0;
         int prev=0;
            // int curr=0;
            int cnt=0;
         for(int i=0;i<bank.size();i++){
            bool f=false;
            for(int j=0;j<bank[0].size();j++){
                if(bank[i][j]=='1') f=true;
                if(bank[i][j]=='1') cnt++;       
           } 
         if(f){
           ans+=(prev*cnt);
           prev=cnt;
           cnt=0;
         }

         }
         return ans;
    }
};