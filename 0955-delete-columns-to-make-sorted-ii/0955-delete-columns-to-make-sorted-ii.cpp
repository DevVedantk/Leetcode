class Solution {
public:

bool is_sorted(vector<string>& str){
    for(int i=1;i<str.size();i++){
        if(str[i-1]>str[i]) return false;
    }
    return true;
}
    int minDeletionSize(vector<string>& strs) {
        int cnt=0;
        int n=strs.size();
        vector<string>str1(n);
        for(int i=0;i<strs[0].size();i++){

              vector<string>str2(str1);
              for(int j=0;j<n;j++){
                str2[j]+=strs[j][i];
              }  

             if(is_sorted(str2)){
                str1=str2;
             } else cnt++;

        }
        return cnt;

    }
};