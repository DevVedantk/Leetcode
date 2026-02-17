class Solution {
public:
 string binary(int n){
     string ans="";
     while(n>0){
         int rem=n%2;
         ans+=to_string(rem);
         n/=2;
     }
     if(n>0) ans+=to_string(n);
     reverse(ans.begin(),ans.end());
     return ans;
 }   
    int minimumFlips(int n) {
        string s=binary(n);
       string rev=s;
         reverse(rev.begin(),rev.end());
     int cnt=0;
        for(int i=0;i<s.size();i++) if(s[i]!=rev[i]) cnt++;
        return cnt;
    }
};