class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0;

        for(int i=0;i<patterns.size();i++){
            string s=patterns[i];
            if(s.size()>word.size()) continue;

             for(int j=0;j<word.size();j++){
                bool f=true;
                int idx=0;
                 for(int k=j;k<j+s.size();k++){
                    if(s[idx]!=word[k]){
                        f=false;
                        break;
                    }
                    idx++;
                 }
                 if(f){
                    cnt++;
                    break;
                 }
             }
        }

        return cnt;
    }
};