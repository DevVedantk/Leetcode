class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
         map<string,vector<string>>mp;
          
          int n=code.size();
         for(int i=0;i<n;i++){
            if(!isActive[i]) continue;
            if(businessLine[i]!="electronics" && businessLine[i]!="grocery" &&
            businessLine[i]!="pharmacy" && businessLine[i]!="restaurant") continue;
             if(code[i]=="") continue;

            bool f=true;
           for(int j=0;j<code[i].size();j++){
            int ascii=(int)code[i][j];
            if(code[i][j]=='_' || (ascii>=65 && ascii<=90) || (ascii>=97 && ascii<=122) ||
            ascii>=48 && ascii<=57){
                f=true;
            } else{
                f=false;
                break;
            }
           }
           if(f){
            mp[businessLine[i]].push_back(code[i]);
           }               
         }
         
        //  cout << mp.size() << endl;
        vector<string>ans;
          for(auto ele:mp){
             vector<string>temp=ele.second;
             sort(temp.begin(),temp.end());
           for(int i=0;i<temp.size();i++) ans.push_back(temp[i]);
          }

         return ans;

    }
};