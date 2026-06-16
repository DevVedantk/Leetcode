class Solution {
public:
    string processStr(string s) {
         string ans="";

         for(int i=0;i<s.size();i++){
            if(s[i]=='#') ans+=ans;
            else if(s[i]=='%'){
                reverse(ans.begin(),ans.end());
            } else if(s[i]=='*'){
                 string s1=ans.substr(0,ans.size()-1);
                 ans=s1;
            } else ans+=s[i];
         }

         return ans;
    }
};