class Solution {
public:
int area(vector<int>& arr){
    int n=arr.size();
    vector<int>prevsm(n);
    prevsm[0]=-1;
    stack<int>st;
    st.push(0);
    int j=1;
    while(j<n){
        while(st.size()>0 && arr[st.top()]>=arr[j]) st.pop();
        if(st.size()==0){
            prevsm[j]=-1;
        } else prevsm[j]=st.top();
        st.push(j);
        j++;
    } 
    while(st.size()>0) st.pop();

    vector<int>nextsm(n);
    nextsm[n-1]=-1;
    st.push(n-1);
    j=n-2;
    while(j>=0){
      while(st.size()>0 && arr[st.top()]>=arr[j]) st.pop();
      if(st.size()==0){
        nextsm[j]=-1;
      } else nextsm[j]=st.top();
      st.push(j);
      j--;
    }
  
     
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
       
        int left= ((prevsm[i]==-1) ? -1 : prevsm[i])+1;
        int right=((nextsm[i]==-1) ? n : nextsm[i])-1;
        int ht=arr[i];
        if(ht==0) continue;
        ht=min(ht,arr[left]);
        ht=min(ht,arr[right]);
        int width=right-left+1;
        ans=max(ans,ht*width);
    } 
    return ans;
}

    int maximalRectangle(vector<vector<char>>& matrix) {
    //    vector<int>arr={2,0,2,1,1}; 
    int n=matrix[0].size();
     int ans=0;
   vector<int>arr(n,0);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]=='1') arr[j]++;
            else arr[j]=0;
        }
        ans=max(ans,area(arr));
    }  
          return ans;
    }
};