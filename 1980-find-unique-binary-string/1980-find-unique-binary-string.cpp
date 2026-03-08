class Solution {
public:
string bin(int n,int len){
    string s="";

    while(n>0){
        int rem=n%2;
        n/=2;
        s+=to_string(rem);
    }
    while(s.size()<len) s+='0';
    reverse(s.begin(),s.end());
   
   return s;

}
    string findDifferentBinaryString(vector<string>& arr) {
        
        set<string>st;
        for(int i=0;i<arr.size();i++) st.insert(arr[i]);

        string ans="";
           
        for(int i=0;i<=arr.size();i++){
           string s=bin(i,arr.size());
        //    cout << "s " << s << endl;
            if(st.find(s)==st.end()) ans=s;
        }
        return ans;
    }
};