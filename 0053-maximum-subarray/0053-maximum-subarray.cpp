class Solution {
public:

struct Node{
  int sum=0;
  int pref_max=INT_MIN;
  int suff_max=INT_MIN;
  int maxsum=INT_MIN;
};
 
vector<Node>sgt;
vector<int>lazy;
 
Node merge(const Node& left,const Node& right){
    
    //  if(left.pref_max == LLONG_MIN) return right;
    // if(right.pref_max == LLONG_MIN) return left;
 
    
    Node res;
    res.sum=left.sum+right.sum;
   res.pref_max=max(left.pref_max,left.sum+right.pref_max);
   res.suff_max=max(right.suff_max,right.sum+left.suff_max);
   
   res.maxsum=max({left.maxsum,right.maxsum,left.suff_max+right.pref_max});
   return res;
}
 
void buildt(int i,int l,int r,vector<int>&arr){
   if(l==r){
       sgt[i].sum=arr[l];
       sgt[i].pref_max=arr[l];
       sgt[i].suff_max=arr[l];
       sgt[i].maxsum=arr[l];
       return;
   }
   int mid=(l+r)/2;
   buildt(2*i+1,l,mid,arr);
   buildt(2*i+2,mid+1,r,arr);
   sgt[i]=merge(sgt[2*i+1],sgt[2*i+2]);
}
 
Node query(int i,int l,int r,int st,int en){
    
    if(st>r || l>en) return Node();
    
 
    if(l>=st && r<=en) return sgt[i];
    int mid=(l+r)/2;
    
    Node left=query(2*i+1,l,mid,st,en);
    Node right=query(2*i+2,mid+1,r,st,en);
    
    return merge(left,right);
}


    int maxSubArray(vector<int>& arr) {
        
      int n=arr.size();

         sgt.assign(4*n,Node());
          buildt(0,0,n-1,arr);
           Node ans=query(0,0,n-1,0,n-1);
           return ans.maxsum;  
    }
};