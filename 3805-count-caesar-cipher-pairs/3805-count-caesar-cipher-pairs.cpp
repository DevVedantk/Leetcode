class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long ans=0;
        map<string,long long>mp;
        for(int i=0;i<words.size();i++){
            int rotation=(26-(words[i][0]-'a'+1))+1;
             string s="1";
            for(int j=1;j<words[i].size();j++){
              int num=words[i][j]-'a'+1;
              int fnum=(num+rotation)%26;
              s+=to_string(fnum);
            }
           if(mp.find(s)!=mp.end()){
            int freq=mp[s];
              ans+=(freq);
           }
           mp[s]++;
        }
        return ans;
    }
};