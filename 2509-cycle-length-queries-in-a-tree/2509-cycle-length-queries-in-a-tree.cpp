class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& que) {
        vector<int>ans;
            for(int i=0;i<que.size();i++){
                int u=que[i][0];
                int v=que[i][1];

                if(v>u) swap(u,v);
                   
                   int cnt=0;
                while(u!=v){
                   cnt++;
                   u/=2;
                   if(v>u) swap(u,v); 
                }
                ans.push_back(cnt+1);
            }
return ans;
          
    }
};