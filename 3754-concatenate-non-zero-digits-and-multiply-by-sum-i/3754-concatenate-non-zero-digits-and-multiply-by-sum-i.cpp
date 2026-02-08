class Solution {
public:
    long long sumAndMultiply(int n) {
        
        string s=to_string(n);
        long long sum=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='0') ans+=s[i];
            sum+=(s[i]-'0');
        }
        
        if(sum==0) return 0;
       long long num=sum*(stoi(ans));
       return num;
    }
};