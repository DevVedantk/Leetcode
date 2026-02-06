class Solution {
public:
vector<int>sgt;

void update(int i,int l,int r,int idx,int val){
    if(l==r){
       sgt[i]=max(sgt[i],val);
       return;
    }

    int mid=(l+r)/2;

    if(idx<=mid) update(2*i+1,l,mid,idx,val);
    else update(2*i+2,mid+1,r,idx,val);
    sgt[i]=max(sgt[2*i+1],sgt[2*i+2]);
}

int query(int st,int en,int i,int l,int r){
    if(st>r || l>en) return -1e5;
    if(l>=st && r<=en) return sgt[i];

    int mid=(l+r)/2;

    int left=query(st,en,2*i+1,l,mid);
    int right=query(st,en,2*i+2,mid+1,r);
    return max(left,right);
}

int lengthOfLIS(vector<int>& arr, int k) {
 int n=arr.size();
       int mx_size=0;
    for(int i=0;i<n;i++) {
        // cin >> arr[i];
        mx_size=max(mx_size,arr[i]);
    }
      sgt.assign(4*(mx_size+1),0);
      
    //   int ans=0;
      int ans=INT_MIN;
    
    for(int i=0;i<arr.size();i++){
 int mx=query(max(0,arr[i]-k),min(mx_size,arr[i]-1),0,0,mx_size)+1;
        update(0,0,mx_size,arr[i],mx);
        ans=max(ans,mx);
    }    
      return ans;
    }
};