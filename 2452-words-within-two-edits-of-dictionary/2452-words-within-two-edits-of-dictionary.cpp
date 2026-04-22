class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string>ans;

        for(int i=0;i<q.size();i++){
            string s1=q[i];
            for(int j=0;j<d.size();j++){
                string s2=d[j];
                int cnt=0;
                for(int k=0;k<s1.size();k++){
                    if(s2[k]!=s1[k]) cnt++;
                    if(cnt>2) break;
                }
                if(cnt<=2) {
                    ans.push_back(s1);
                    break;
                }
            }
        }

        return ans;
    }
};