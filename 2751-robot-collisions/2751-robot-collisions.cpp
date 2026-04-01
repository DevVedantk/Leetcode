class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<tuple<int,int,int>>arr;
        map<int,char>dir;
        for(int i=0;i<positions.size();i++){
            arr.push_back({positions[i],healths[i],i});
            dir[positions[i]]=directions[i];
        }
   
  
        sort(arr.begin(),arr.end());
        int i=0;
        stack<tuple<char,int,int>>st;
       
        while(i<arr.size()){
           auto [pos, currh, idx] = arr[i];
             char currDir = dir[pos];
              if(st.size()==0 || get<0>(st.top())=='L' || currDir=='R')  st.push({currDir,currh,idx});
              else{
              bool alive=true;
                  while(st.size()>0 && (get<0>(st.top())=='R')){
                    auto [d,health,index]=st.top();
                    st.pop();
                    if(health==currh){
                        alive=false;
                         break;
                    }
                    if(health!=currh){
                       if(health>currh){
                        alive=false;
                        st.push({d,health-1,index});
                        break;
                       }
                       else {
                        currh--;
                       }
                    }
                  }
                  if(alive){
                    st.push({currDir,currh,idx});
                  }
              }
              i++;  
        }

        vector<pair<int,int>>ans;
        while(st.size()>0){
             auto [d,health,index]=st.top();
                    st.pop();

                    ans.push_back({index,health});
        }
        sort(ans.begin(),ans.end());
        vector<int>f;
        for(auto ele:ans) f.push_back(ele.second);
        // reverse(ans.begin(),ans.end());

    return f;

    }
};