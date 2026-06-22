class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>cnt(5,0);
        for(int i=0;i<text.size();i++){
            if(text[i]=='b') cnt[0]++;
            if(text[i]=='a') cnt[1]++;
            if(text[i]=='l') cnt[2]++;
            if(text[i]=='o') cnt[3]++;
            if(text[i]=='n') cnt[4]++;
        }

        int ans=INT_MAX;
        ans=min(ans,cnt[0]);
        ans=min(ans,cnt[1]);
        ans=min(ans,cnt[2]/2);
        ans=min(ans,cnt[3]/2);
        ans=min(ans,cnt[4]);
        return ans;

    }
};