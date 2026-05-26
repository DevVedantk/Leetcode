class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int>mp;
        for(int i=0;i<word.size();i++){
            if((int)word[i]>=97 && (int)word[i]<=122){
                mp[word[i]-97]=i;
            }
        }

        //lowercase max index
         
         vector<bool>vis(26,false);
        int cnt=0;
        for(int i=0;i<word.size();i++){
            if((int)word[i]>=97 && (int)word[i]<=122) continue;
            if((int)word[i]>=65 && (int)word[i]<=90){
               if(mp.find(word[i]-65)!=mp.end() && !vis[word[i]-65] && mp[word[i]-65]<i){
                cnt++;
               } 
                vis[word[i]-65]=true;
                
            }
        }
        return cnt;
    }
};