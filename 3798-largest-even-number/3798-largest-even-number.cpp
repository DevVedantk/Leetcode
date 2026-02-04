class Solution {
public:
    string largestEven(string s) {
        int i=s.size()-1;
       
    while(i>=0 && s[i]!='2' && s[i]!='0' && s[i]!='4' && s[i]!='6' && s[i]!='8'){
            i--;
        }

        return s.substr(0,i+1);

    }
};