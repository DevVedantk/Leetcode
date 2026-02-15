class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& wt) {
   map<int,char>mp;
        char ch='z';
        for(int i=0;i<=25;i++){
            mp[i]=ch;
            ch--;
        }
        
        string ans="";
        int n=words.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<words[i].size();j++) sum+=wt[(words[i][j]-'a')];
            int val=sum%26;
             ans+=mp[val];
        }
   // char c=1+'a';
        // cout << c << endl;
        // cout << ans << endl;
        return ans;
    }
};