class Solution {
public:
    vector<int> plusOne(vector<int>& dg) {
        
        vector<int>ans;
        int n=dg.size();
        int carry=0;
         
         if(dg[n-1]+1>9){
            ans.push_back((dg[n-1]+1)%10);
            carry=1;
         } else ans.push_back((dg[n-1]+1));
         

        for(int i=n-2;i>=0;i--){
           if((dg[i]+carry)>9){
            ans.push_back((dg[i]+carry)%10);
            carry=1;
           } else{
           ans.push_back((dg[i]+carry));
            carry=0;
           }
        }
        if(carry==1) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;

    }
};