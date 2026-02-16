class Solution {
public:
    int reverseBits(int n) {
        string s="";

        while(n>0){
            int rem=n%2;
            s+=to_string(rem);
            n/=2;
        }
        while(s.size()<32) s+='0';
        cout << s << endl;

        reverse(s.begin(),s.end());
        cout << s << endl;
        int ans=0;
        for(int i=0;i<32;i++){
           if(s[i]=='1') ans+=(pow(2,i));
        }

        return ans;
    }
};