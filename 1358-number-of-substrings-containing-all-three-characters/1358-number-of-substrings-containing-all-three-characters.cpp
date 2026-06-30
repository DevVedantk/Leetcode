class Solution {
public:
    int numberOfSubstrings(string s) {
            
            int cnt=0;
            int i=0,j=0;
            int n=s.size();

            int a=0,b=0,c=0;  
            while(i<n && j<s.size()){
               
                 if(a>=1 && b>=1 && c>=1){
                    int len=n-j;
                    cnt+=(len+1);
                if( s[i]=='a') a--; 
                 if(s[i]=='b') b--; 
                 if(s[i]=='c') c--;
                 i++;
                 }
                  else{
                 if(s[j]=='a') a++; 
                 if(s[j]=='b') b++; 
                 if(s[j]=='c') c++;
                 j++;
                  } 
            }
            //  cout << i << " " << cnt << endl;
              while(i<n){
                 if(a>=1 && b>=1 && c>=1){
                    cnt++;
                 }   
                 if(s[i]=='a') a--; 
                 if(s[i]=='b') b--; 
                 if(s[i]=='c') c--;
                i++;
              }
return cnt;
    }
};