class Solution {
public:
    int minimumBoxes(vector<int>& ap, vector<int>& c) {
        int sum=0;
      for(int i=0;i<ap.size();i++) sum+=ap[i];
      sort(c.begin(),c.end());
      int cnt=0;

      int i=c.size()-1;
      int s2=0;
      while(i>=0 && s2<sum){
        s2+=c[i];
        i--;
        cnt++;
      }

      return cnt;
    }
};