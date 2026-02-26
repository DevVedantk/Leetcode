class Solution {
public:
string solve(string& s,int& k){
      stack<char>st;

        vector<int>ans;
        //open // closing
        int n=s.size();
        int i=0;
        int closing=0;
        bool flag=false;
        while(i<n){
            closing=0;
            flag=false;

            if(s[i]=='('){
                st.push(s[i]);
                i++;
            }
            else {
                while(i<n && s[i]==')' && closing<k){
                    closing++;
                    i++;
                }

                if(closing<k || st.size()<k){
                    cout << st.size() <<" " << closing << endl;
                    ans.push_back(st.size());
                    ans.push_back(closing);
                    flag=true;
                  while(st.size()>0)  st.pop();
                } else if(closing==k && st.size()>=k){
                    while(closing>0){
                        st.pop();
                        closing--;
                    }
                }
            }
        }
        if(!flag){
         ans.push_back(st.size());
         ans.push_back(closing);
        }
      
      string str="";
       for(int i=0;i<ans.size();i++){
            int ele=ans[i];
          if(i%2==0){
            while(ele>0){
                 str+='(';
                 ele--;
            }
          } else{
            while(ele>0){
                 str+=')';
                 ele--;
            }
          }
       }

        return str;
}
    string removeSubstring(string s, int k) {
        
        string ans1=solve(s,k);
        return solve(ans1,k);
    }
};