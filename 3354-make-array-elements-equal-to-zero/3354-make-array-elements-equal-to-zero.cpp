class Solution {
public:
bool check(vector<int>arr ,bool left,int i){
  
     while(i>=0 && i<arr.size()){
        if(left) i--;
        else i++;
        if(i<0 || i>=arr.size()) break;
        if(arr[i]>0){
            arr[i]=arr[i]-1;
            left=!left;
        } 
   }
    
    bool flag=true;
   for(int i=0;i<arr.size();i++){
     if(arr[i]!=0) flag=false;
   }

   return flag;
}
int countValidSelections(vector<int>& arr) {
        int cnt=0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                //first left
             if(check(arr,true,i)) cnt++;

             //second right
             if(check(arr,false,i)) cnt++;
            }
        }
        return cnt;

    }
};