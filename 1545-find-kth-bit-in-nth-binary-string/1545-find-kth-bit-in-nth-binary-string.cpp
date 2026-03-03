class Solution {
public:

string binary(string& s){
    string ns="";
    ns+=s;
    ns+='1';
    reverse(s.begin(),s.end());

    for(int i=0;i<s.size();i++){
        if(s[i]=='1') ns+='0';
        else ns+='1';
    }

    return ns;
}
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=2;i<=n;i++){
          s=binary(s);
        }
        cout << s << endl;
        return s[k-1];
    }
};