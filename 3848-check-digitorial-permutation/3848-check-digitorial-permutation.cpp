class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int>fact={1,1,2,6,24,120,720,5040,40320,362880};

        int dn=n;
         map<int,int>mp;
         int perm=0;
           while(dn>0){
            int rem=dn%10;
            // cout << "rem " << rem << endl;
            perm+=fact[rem];
            mp[rem]++;
            dn/=10;
           }
        
            // cout << perm << endl;
          while(perm>0){
            int rem=perm%10;
            if(mp.find(rem)==mp.end()) return false;
            if(mp[rem]==1) mp.erase(rem);
            else mp[rem]--;
            perm/=10;
          }

        //   cout << perm << endl;
        if(mp.size()==0) return true;
        return false;

    }
};