class Solution {
public:
 bool check(string& s){
    // cout << "hee" << endl;
    int n=s.size();
    for(int i=n-2;i>=0;i--){
        if(s[i]!='0') return false;
    }
    if(s[n-1]=='1') return true;
    return false;
 }

string addone(string& s){
    string ans="";
     int n=s.size();
     int carry=0;
     if(s[n-1]=='1'){
        ans+='0';
        carry=1;
     }

    for(int i=n-2;i>=0;i--){
        if(s[i]=='1' && carry==1){
            ans+='0';
            carry=1;
        } else {
          if(carry==1 || s[i]=='1') ans+='1';
          else ans+='0';
          carry=0; 
        } 
    }
    
    if(carry==1) ans+='1';

    reverse(ans.begin(),ans.end());
    return ans;
}
    
int numSteps(string s) {
         
         int ans=0;
         int n=s.size();
        //   cout << s.substr(0,n-1) << endl;
         while(!check(s)){
             n=s.size();
            if(s[n-1]=='1'){
                // cout << "aa" << endl;
                s=addone(s);
            // cout << s << endl;
            // cout << "ye" << endl;
            } else {
                s=s.substr(0,n-1);
            }
            ans++;
         }
         return ans;

    }
};