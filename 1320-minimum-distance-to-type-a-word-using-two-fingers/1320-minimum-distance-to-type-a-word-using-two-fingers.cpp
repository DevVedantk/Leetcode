class Solution {
public:
int dp[301][27][27];
        map<int,pair<int,int>>mp;
    int solve(int idx,string word,int f1,int f2){
        if(idx>=word.size()) return 0;
        int ans=1e9;
      
      if(dp[idx][f1][f2]!=-1) return dp[idx][f1][f2];
        if(f1==0){
         //not done yet
          ans=min(ans,solve(idx+1,word,word[idx]-'A'+1,f2));
        // if(f2==0) ans=min(ans,solve(idx+1,word,f1,word[idx]-'A'+1));
        } else{
            //may this current word by f1
            auto prev=mp[f1];
            auto curr=mp[word[idx]-'A'+1];
            int dist=abs(prev.first-curr.first)+abs(prev.second-curr.second);
            ans=min(ans,dist+solve(idx+1,word,word[idx]-'A'+1,f2));
        } 

        if(f2==0){
            ans=min(ans,solve(idx+1,word,f1,word[idx]-'A'+1));
        } else{
            //may this current word by f2
            auto prev=mp[f2];
            auto curr=mp[word[idx]-'A'+1];
            int dist=abs(prev.first-curr.first)+abs(prev.second-curr.second);
            ans=min(ans,dist+solve(idx+1,word,f1,word[idx]-'A'+1));
        }
    return dp[idx][f1][f2]=ans;
    }
    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
        int x=0,y=0;
        for(int i=1;i<=26;i++){
            mp[i]={x,y};
            if(i%6==0) x++;
            if(y==5) y=0;
            else y++; 
        }

      return solve(0,word,0,0);

    }
};