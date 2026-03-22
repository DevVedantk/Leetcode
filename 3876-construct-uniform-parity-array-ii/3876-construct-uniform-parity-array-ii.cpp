class Solution {
public:
    bool uniformArray(vector<int>& arr) {

        int even=INT_MAX,odd=INT_MAX;
        for(int i=0;i<arr.size();i++){
           if(arr[i]%2==0) even=min(even,arr[i]);
            else odd=min(odd,arr[i]);
        }

        // for even
        bool f1=true;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0) continue;
            if(arr[i]-odd<1) f1=false;
        }

          // for odd
        bool f2=true;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0) continue;
            if(arr[i]-odd<1) f2=false;
        }

        if(f1==true || f2==true) return true;
        return false;
        
    }
};