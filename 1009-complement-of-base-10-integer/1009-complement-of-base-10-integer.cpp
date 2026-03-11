class Solution {
public:
int power(int a,int b){
    if(b==0) return 1;
    
    int half=power(a,b/2);
    if(b%2==0) return half*half;
    return half*half*a; 
}
    int bitwiseComplement(int n) {
          if(n==0) return 1;
        string bin=""; 
       
       while(n>0){
         int rem=n%2;
         bin+=to_string(rem);
         n/=2;
       }
      int ans=0;
      string comp="";
      for(int i=0;i<bin.size();i++){
        if(bin[i]=='0') comp+='1';
        else comp+='0';
      }
      for(int i=0;i<bin.size();i++){
        ans=ans+((comp[i]-'0')*(power(2,i)));
      } 

    cout << bin << endl;
       return ans;
    }
};