class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {

         string s1=words[0];
                // string s2=words[j];
        // cout << s1.substr(0,k) << endl;
         int cnt=0;
        map<string,int>mp;
        for(int i=0;i<words.size();i++){
            if(words[i].size()<k) continue;
            mp[words[i].substr(0,k)]++;
        }

         for(auto ele:mp){
             if(ele.second>=2) cnt++;
         }
        return cnt;
    }
};