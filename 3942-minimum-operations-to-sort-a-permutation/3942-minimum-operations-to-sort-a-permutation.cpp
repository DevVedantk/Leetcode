class Solution {
public:

    int check(vector<int>&arr){
        int n=arr.size();
        int idx=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) {
                idx=i;
                break;
            }
        }
        
       bool c1=true,c2=true;
        if(idx<n){
            bool f=true;
            int find=0;
            int d1=idx;
            while(f){
               if(d1<n && arr[d1]==find){
                   find++;
                   d1++;
                   if(find==n) f=false;
                   if(d1==n) d1=0;
               } else{
                   c1=false;
                    break;
               }   
            }
        }

    // cout << "idx " << idx << endl;
        if(idx>=0){
            int d2=idx;
            bool f=true;
            int find=0;
            while(f){
               if(d2>=0 && arr[d2]==find){
                   find++;
                   d2--;
                   if(find==n) f=false;
                   if(d2==-1) d2=n-1;
               } else{
                   c2=false;
                    break;
               }   
            }
        }

        // cout  <<"here " << c1 << " " << c2 << endl;
  
        if(c1) return 1;
        if(c2) return 2;
        return -1;
        // return  (c1 || c2);
    }
    int minOperations(vector<int>& arr) {
         int ans=check(arr);
        if(ans==-1) return -1;
        cout << ans << endl;
        int n=arr.size();
        if(ans!=-1 && arr[0]==0 && arr[n-1]==n-1) return 0;

        int idx=0;
            while(idx<arr.size() && arr[idx]!=0){
                idx++;
            }

        

        bool rev=false;
        if(ans==1){
              int left=idx;
        int right=(n-1)-idx+1;
 cout <<"l r " << left << " " << right << endl;
    
            if(left>right){
                return min(left,right+2);
            } else return left; 
        } else if(ans==2){
            
                int left=idx+1;
        int right=(n-1)-idx;
       

            if(left>right){
                return right+1;
            } else return left+1;
        }
        return -1;
    }
};