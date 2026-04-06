class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
          set<pair<int,int>>st;
          for(int i=0;i<obs.size();i++){
            st.insert({obs[i][0],obs[i][1]});
          }

          bool n=true,s=false,e=false,w=false;
          int x=0,y=0;
      int ans=0;
      for(int i=0;i<commands.size();i++){
          if(commands[i]<0){
            if(commands[i]==-1){
                if(n){
                    n=false;
                    e=true;
                } else if(e){
                    e=false;
                    s=true;
                } else if(s){
                    s=false;
                    w=true;
                } else if(w){
                    w=false;
                    n=true;
                }
            } else{
                   if(n){
                    n=false;
                    w=true;
                } else if(e){
                    e=false;
                    n=true;
                } else if(s){
                    s=false;
                    e=true;
                } else if(w){
                    w=false;
                    s=true;
                }
            }
          } else{
            //  cout << "dir" << e << " " << w << " " << n << " " <<s << endl;
           for(int j=0;j<commands[i];j++){
            if(n) y++;
            if(s) y--;
            if(e) x++;
            if(w) x--;

            if(st.find({x,y})!=st.end()){
            if(n) y--;
            if(s) y++;
            if(e) x--;
            if(w) x++;
            break;
            }
            // cout << "x y " << x << " " << y << endl;
            ans=max(ans,x*x+y*y);
           }

          }
      }
      return ans;
  
    }
};