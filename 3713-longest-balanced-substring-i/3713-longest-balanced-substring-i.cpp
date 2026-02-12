class Solution {
public:
    int longestBalanced(string s) {
         int n=s.size();
         int ans=0;
         for(int i=0;i<s.size();i++){
            map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                bool same=true;
               int freq=-1;
               for(auto ele:mp){
                if(freq==-1) freq=ele.second;
                else if(freq!=ele.second) same=false;
               }
               if(same) ans=max(ans,j-i+1);
            }
         }
         return ans;
    }
};