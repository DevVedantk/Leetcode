class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<int>st;
        for(int i=0;i<word.size();i++){
            if((int)word[i]>=65 && (int)word[i]<=90){
                st.insert(word[i]-65);
            }
        }

        int cnt=0;
        vector<bool>vis(26,false);
        for(int i=0;i<word.size();i++){
            if((int)word[i]>=97 && (int)word[i]<=122){
                if(!vis[word[i]-97] && st.find(word[i]-97)!=st.end()){
                     cnt++;
                     vis[word[i]-97]=true;
                }
            } 
        }

        return cnt;
    }
};