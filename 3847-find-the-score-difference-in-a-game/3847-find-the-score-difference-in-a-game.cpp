class Solution {
public:
    int scoreDifference(vector<int>& arr) {
        int p1=0,p2=0;
        bool p1a=true,p2a=false;

        for(int i=0;i<arr.size();i++){
            if((i+1)%6==0)swap(p1a,p2a);
            if(arr[i]%2!=0)swap(p1a,p2a);
            
            if(p1a) {
                p1+=arr[i];
              
            }
            else if(p2a) {
             
                p2+=arr[i];}
            
        }
  
        return p1-p2;
    }
};