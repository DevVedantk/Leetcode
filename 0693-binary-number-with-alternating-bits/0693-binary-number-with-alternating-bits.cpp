class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s="";
        while(n>0){
            int rem=n%2;
            n/=2;
            s+=to_string(rem);
        }
        
        
        bool st=false;
        if(s[0]=='1') st=true;
        for(int i=0;i<s.size();i++){
            if(st==true && (i%2==0 && s[i]!='1')) return false;
            if(st==true && (i%2!=0 && s[i]=='1')) return false;
            
            if(st==false && (i%2==0 && s[i]!='0')) return false;
            if(st==false && (i%2!=0 && s[i]=='0')) return false;
        }
        return true;
    }
};