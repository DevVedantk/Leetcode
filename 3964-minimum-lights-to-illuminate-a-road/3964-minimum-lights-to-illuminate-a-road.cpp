class Solution {
public:
    int minLights(vector<int>& arr) {
         vector<pair<int,int>>intervals;
         int n=arr.size();
         for(int i=0;i<arr.size();i++){
            if(arr[i]>0){
                int l=max(0,i-arr[i]);
                int r=min(n-1,i+arr[i]);
                intervals.push_back({l,r});
            }
         }
         sort(intervals.begin(),intervals.end());
         for(auto [l,r]:intervals){
            cout << l << " " << r << endl;
         }
         cout << endl;

         vector<pair<int,int>>merge;

        if(intervals.size()>0) merge.push_back({intervals[0].first,intervals[0].second});
         
        int i=1;
        while(i<intervals.size()){
             auto [currL,currR]=intervals[i];
             auto [prevL,prevR]=merge[merge.size()-1];
             if(currL>=prevL && currL<=prevR && currR>prevR){
                merge[merge.size()-1].first=prevL;
                merge[merge.size()-1].second=currR;
             } else if(currL>prevR) merge.push_back({currL,currR});
             i++;
        }
        for(auto [l,r]:merge) cout << l << " " << r << endl;

        if(merge.size()==0){
            return (n+2)/3;
        }
         
          int extra=0;
          //handle first gap
          auto [l,r]=merge[0];
          int len=l;
          extra+=((len+2)/3);

          
          auto [lastl,lastr]=merge[merge.size()-1];
          //handle last gap
          len=(n-1)-(lastr);
          extra+=((len+2)/3);

          for(int i=1;i<merge.size();i++){
               auto [prevL,prevR]=merge[i-1];
               auto [currL,currR]=merge[i];
               len=currL-prevR-1;
               extra+=((len+2)/3);
          }

        return extra; 
    }
};