class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& b) {
        int n=b.size();
        vector<bool>tog(101,false);
        for(int i=0;i<b.size();i++){
            tog[b[i]]=!tog[b[i]];
        }

        vector<int>ans;
        for(int i=1;i<=100;i++){
            if(tog[i]==true) ans.push_back(i);
        }

        return ans;
    }
};