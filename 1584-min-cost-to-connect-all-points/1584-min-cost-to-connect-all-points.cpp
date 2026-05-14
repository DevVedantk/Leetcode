class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        set<pair<int,int>>vis;
        
   priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    int x=points[0][0],y=points[0][1];

       pq.push({0,x,y});
  
  int t=0;
       while(pq.size()>0){
        auto [m_dis,x,y]=pq.top();
        pq.pop();
        
        if(vis.find(make_pair(x,y))!=vis.end()) continue;
        vis.insert({x,y});
        t+=m_dis;

        for(int i=0;i<points.size();i++){
            int x1=points[i][0],y1=points[i][1];
            if(x1==x && y1==y) continue;
              if(vis.find(make_pair(x1,y1))==vis.end()){
                   int dis=abs(x1-x)+abs(y1-y);
                   pq.push({dis,x1,y1});  
              }
        }
       } 

       return t;  


    }
};