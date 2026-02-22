class Solution {
public:
    string maximumXor(string s, string t) {
        map<char,int>mp;
        for(int i=0;i<t.size();i++) mp[t[i]]++;
        
        string ns="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(mp.find('1')!=mp.end()){
                    ns+='1';
                   if(mp['1']==1) mp.erase('1');
                   else mp['1']--;
                } else {
                    ns+='0';
                     if(mp['0']==1) mp.erase('0');
                   else mp['0']--;
                } 
            } else{
               
               if(mp.find('0')!=mp.end()){
                    ns+='0';
                   if(mp['0']==1) mp.erase('0');
                   else mp['0']--;
                } else {
                    ns+='1';
                     if(mp['1']==1) mp.erase('1');
                   else mp['1']--;
                }
            }
        }


    string ans="";
    for(int i=0;i<s.size();i++){
        if(s[i]==ns[i]) ans+='0';
        else ans+='1';
    }

    return ans;
    }
};