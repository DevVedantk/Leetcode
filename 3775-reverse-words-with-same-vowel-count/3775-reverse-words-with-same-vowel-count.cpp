class Solution {
public:
void rev(string& s,int i,int j){
       while(i<j){
           swap(s[i],s[j]);
           i++;
           j--;
       }
}
    string reverseWords(string s) {
      int cnt=0;
        int i=0;
        while(i<s.size() && s[i]!=' '){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||
              s[i]=='u') cnt++;
            i++;
        }
        i++;
        
       while(i<s.size()){
          int vcnt=0;
           int j=i;
             while(j<s.size() && s[j]!=' '){
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' ||
              s[j]=='u') vcnt++;
            j++;   
             }
        if(vcnt==cnt){
            rev(s,i,j-1);
        }   
           j++;
           i=j;
           
       }
        cout << s << endl;
        return s;
        
        
        
    }
};