class Solution {
public:
    string lexSmallest(string s) {
        string ans=s;
        string f1="",f2="";
        for(int i=0;i<s.size();i++){
            // string rev="";
           string s1=s.substr(0,i);
           string s2=s.substr(i);
           reverse(s1.begin(),s1.end());
          f1=s1+s.substr(i);
            ans=min(ans,f1);
reverse(s2.begin(),s2.end());
           f2=s.substr(0,i)+s2;
            ans=min(ans,f2);

        }

        return ans;
    }
};