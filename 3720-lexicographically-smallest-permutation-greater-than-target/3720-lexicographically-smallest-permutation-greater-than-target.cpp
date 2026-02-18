class Solution {
public:

void lb(string& s,int lo,int hi,map<char,int>&mp,vector<char>& ans){
    for(int i=lo;i<=hi && i>=0;i++){
        auto it=mp.lower_bound(s[i]);
        if(it==mp.end()) it=mp.begin();
       if(it!=mp.end()){
        ans[i]=it->first;
         if(it->second==1) mp.erase(it);
        else mp[ans[i]]--;
       }
    }
}

void sorted(int lo,map<char,int>&mp,vector<char>& ans){
     int idx=lo;
    for(auto ele:mp){
        for(int i=0;i<ele.second && idx<(int)ans.size();i++){
            ans[idx]=ele.first;
            idx++;
        }
    }
}

string solve(string& s,map<char,int> mp,char c,int idx){
     int n=s.size();
     vector<char>ans(n);
    
    ans[idx]=c;
    if(mp[c]==1) mp.erase(c);
    else mp[c]--;

    lb(s,0,idx-1,mp,ans);
    sorted(idx+1,mp,ans);

    string perm="";
    for(int i=0;i<ans.size();i++) perm+=ans[i];

    return perm;
}

string lexGreaterPermutation(string s, string target) {
           
           map<char,int>mp;
           for(int i=0;i<s.size();i++) mp[s[i]]++;

           string ans="";

           for(int j=0;j<target.size();j++){
               vector<char>upperB;
               auto it=mp.upper_bound(target[j]);
               for(;it!=mp.end();it++) upperB.push_back(it->first);

               for(int i=0;i<upperB.size();i++){
                string s=solve(target,mp,upperB[i],j);
                if(ans=="" && s>target) ans=s;
                 else if(s>target && ans!="") ans=min(ans,s);
               }
           }

           return ans>target ? ans : ""; 
           
    }
};