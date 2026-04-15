class Solution {
public:
    int closestTarget(vector<string>& words, string target, int st) {
            int n=words.size();
          int i=st;
          int cnt=0;
          int ans=INT_MAX;
          while(cnt<words.size()){
            if(i==-1) i=n-1;
            if(words[i]==target){
                ans=min(ans,cnt);
                break;
            }
            cnt++;
            i--; 
          }

          i=st;
          cnt=0;

           while(cnt<words.size()){
            if(i==n) i=0;
            if(words[i]==target){
                ans=min(ans,cnt);
                break;
            }
            cnt++;
            i++; 
          }
    return ans==INT_MAX ? -1 : ans;

    }
};