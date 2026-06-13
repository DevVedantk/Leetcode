class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& wt) {
        string ans="";

        for(int i=0;i<words.size();i++){
            string s=words[i];
            int sum=0;
            for(int j=0;j<s.size();j++){
                sum+=(wt[s[j]-'a']);
            }
            sum=sum%26;
            ans+=((char)(122-sum));
        }

        return ans;
    }
};