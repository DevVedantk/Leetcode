class Solution {
public:
vector<string>strs;

void solve(int n,int a,int b,int c,string s){

    //a=1 means last a
    //b=1 means last b
    //c=1 means last c

    if(n==0){ 
        strs.push_back(s);
        return;
    }

    if(a==1){
        solve(n-1,0,1,0,s+'b');
        solve(n-1,0,0,1,s+'c');
    } else if(b==1){
        solve(n-1,1,0,0,s+'a');
        solve(n-1,0,0,1,s+'c');
    } else if(c==1){
        solve(n-1,1,0,0,s+'a');
        solve(n-1,0,1,0,s+'b');
    } else{
        solve(n-1,1,0,0,s+'a');
        solve(n-1,0,0,1,s+'c');
        solve(n-1,0,1,0,s+'b');
    }

}
    string getHappyString(int n, int k) {
        
        solve(n,0,0,0,"");
       
        if(strs.size()<k) return ""; 
         sort(strs.begin(),strs.end());
         return strs[k-1];
    }
};