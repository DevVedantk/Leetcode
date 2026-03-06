class Solution {
public:
    bool checkOnesSegment(string s) {
       
         int i=0;
         while(i<s.size() && s[i]=='1') i++;
       
       
         while(i<s.size()){
            if(s[i]=='1') return false;
            i++;
         }

         return true;
    }
};