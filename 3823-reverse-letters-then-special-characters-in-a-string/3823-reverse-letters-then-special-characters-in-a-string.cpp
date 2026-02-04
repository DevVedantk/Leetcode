class Solution {
public:
    string reverseByType(string s) {

        string let="";
        string sp="";
        for(int i=0;i<s.size();i++){
            if((int)s[i]-97>=0 && (int)s[i]-122<=25) let+=s[i];
            else sp+=s[i];
        }
       reverse(let.begin(),let.end());
       reverse(sp.begin(),sp.end());

        string ans="";
        int i=0,j=0,k=0;
        while(k<s.size()){
            if((int)s[k]-97>=0 && (int)s[k]-122<=25){
                ans+=let[i];
                i++;
            } else {
                ans+=sp[j];
                j++;
            }
            k++;
        }
        // cout << ans << endl;
        return ans;
    }
};