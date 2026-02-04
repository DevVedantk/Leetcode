class Solution {
public:
    vector<int> rotateElements(vector<int>& arr, int k) {
         queue<int>q;
  vector<int>pos;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>=0) q.push(arr[i]);
        }
        // cout << "ele";
        // while(q.size()>0){
        //     int f=q.front();
        //     cout << f << " ";
        // }
        
        // for(int i=0)
        if(q.size()==0) return arr;
        for(int i=0;i<k;i++){
            int f=q.front();
            q.pop();
            q.push(f);
        }
         for(int i=0;i<n;i++){
             if(arr[i]>=0){
                 int f=q.front();
            q.pop();
                 arr[i]=f;
             }
         }
        // for(int i=0;i<)
        // for(int ele:arr) cout << ele << " ";
        return arr;
       
    }
};