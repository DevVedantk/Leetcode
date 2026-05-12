class Solution {
public:

bool check(int en,vector<vector<int>>& tasks){
    
    for(int i=0;i<tasks.size();i++){
        if(en>=tasks[i][1]){
            if((en-tasks[i][0])<0) return false;
            else en-=tasks[i][0];
        } else return false;
    }
    return true;
}
    int minimumEffort(vector<vector<int>>& tasks) {
         int ans=INT_MAX;
    sort(tasks.begin(),tasks.end(),[](auto& a,auto& b){
        return (a[1]-a[0])>(b[1]-b[0]);
    });
       
         int lo=0,hi=1e9;

         while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(check(mid,tasks)){
                ans=mid;
                hi=mid-1;
            } else lo=mid+1;
         }

         return ans;
    }
};