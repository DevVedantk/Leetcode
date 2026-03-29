class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        for(int i=0;i<4;i++){
            if(s1[i]==s2[i]) continue;
            if((i==0 || i==1) && s1[i]!=s2[i]){
               if(s1[i]==s2[i+2]) swap(s2[i],s2[i+2]);
               else if(s2[i]==s1[i+2])swap(s2[i],s1[i+2]);  
            }

             if((i==2 || i==3) && s1[i]!=s2[i]){
               if(s1[i]==s2[i-2]) swap(s1[i],s2[i-2]);
               else if(s2[i]==s1[i-1])swap(s2[i],s1[i-2]);  
            }
        }

        if(s1==s2) return true;
        return false;
    }
};