class Solution {
public:
    int binaryGap(int n) {
        
        vector<int>pos;
        
        int idx=1;
        while(n>0){
          if(n%2!=0) pos.push_back(idx);
          n=n>>1;
          idx++;
        }
   int ans=0;
        for(int i=1;i<pos.size();i++){
            ans=max(ans,pos[i]-pos[i-1]);
        }
        return ans;
    }

};