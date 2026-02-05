class Solution {
public:
vector<int>sgTree;

void buildTree(int i,int l,int r,vector<int>& bas){
    if(l==r){
        sgTree[i]=bas[l];
        return;
    }
 
    int mid=(l+r)/2;
    buildTree(2*i+1,l,mid,bas);
    buildTree(2*i+2,mid+1,r,bas);
    sgTree[i]=max(sgTree[2*i+1],sgTree[2*i+2]);
}

// void update(int idx,int val,int i,int l,int r){
//     if(l==r){
//         sgTree[i]=val;
//         return;
//     }
//     int mid=(l+r)/2;

//     if(idx<=mid) update(idx,val,2*i+1,l,mid);
//     else update(idx,val,2*i+2,mid+1,r); 
    
//     sgTree[i]=min(sgTree[2*i+1],sgTree[2*i+2]);
// }

bool query(int i,int l,int r,int val){
  if(sgTree[i]<val) return false;

  if(l==r){
    sgTree[i]=-1;
    return true;
  }
  
  int mid=(l+r)/2;
  bool placed=false;
  
  if(sgTree[2*i+1]>=val){
    placed=query(2*i+1,l,mid,val);
  } else placed=query(2*i+2,mid+1,r,val);
  
  sgTree[i]=max(sgTree[2*i+1],sgTree[2*i+2]);
  return placed;
 
}

int numOfUnplacedFruits(vector<int>& frt, vector<int>& b) {
        int n=frt.size();
        sgTree.assign(4*n,0);
    
       int ans=0;
       buildTree(0,0,n-1,b);
   for(int i=0;i<n;i++){
      if(query(0,0,n-1,frt[i])==false) ans++;  
     }
    
    return ans;

    }
};