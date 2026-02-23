class Solution {
public:
set<string>st;
void solve(int k,string bin){
    if(k==0){
        st.insert(bin);
        return;
    }

    solve(k-1,bin+"1");
    solve(k-1,bin+"0");
}
    bool hasAllCodes(string s, int k) {
        if(pow(2,k)>s.size()) return false;
        solve(k,"");
        
        set<string>vis;
        for(int i=0;i<=s.size()-k;i++){
           string sub=s.substr(i,k);
           if(st.size()==0) break;
           if(st.find(sub)==st.end() && vis.find(sub)==vis.end()) return false;
            else{
                 st.erase(sub);
                 vis.insert(sub);
            }
        }

        return (st.size()==0);
    }
};