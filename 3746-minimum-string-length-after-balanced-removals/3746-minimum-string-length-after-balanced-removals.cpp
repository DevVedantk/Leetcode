class Solution {
public:
    int minLengthAfterRemovals(string s) {
        map<char,int>mp;
        int i=0;
        while(i<s.size()){
            mp[s[i]]++;
            if(mp.size()==2){
                int a=mp['a'];
                int b=mp['b'];
                int minsize=min(a,b);
                if(mp['a']==minsize) mp.erase('a');
                else mp['a']-=minsize;
                 if(mp['b']==minsize) mp.erase('b');
                else mp['b']-=minsize;
            }
            i++;
        }
   int ans=0;
        if(mp.find('a')!=mp.end()) ans+=mp['a'];
        if(mp.find('b')!=mp.end()) ans+=mp['b'];
        
        
      return ans;
    }
};