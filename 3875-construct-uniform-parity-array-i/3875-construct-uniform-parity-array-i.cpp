class Solution {
public:
    bool check(vector<int>&arr){
        bool even=true;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0) even=false;
        }
        if(even) return true;

        bool odd=true;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0) odd=false;
        }
        if(odd) return true;
        return false;
    }
    bool uniformArray(vector<int>& arr) {

        if(check(arr)) return true;

        vector<int>brr=arr;
        //brr-> odd
        bool odd=false;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0) odd=true;
        }
        

        bool even=false;
         for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0) even=true;
        }

        if(odd==true || even==true) return true;
        return false;
    }
};