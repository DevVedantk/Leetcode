class Solution {
public:
struct Node{

  int maxe=0;
  int mine=0;
};

vector<int>lazy;
vector<Node>sgt;

void propagate(int i,int l,int r){
    if(lazy[i]!=0){
        sgt[i].mine+=lazy[i];
        sgt[i].maxe+=lazy[i];
        if(l!=r){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
}

void updateRange(int st,int en,int i,int l,int r,int val){
     propagate(i,l,r);
    if(st>r || l>en) return;
    if(l>=st && r<=en){
        lazy[i]+=val;
      propagate(i,l,r);        
        return;
    }

    int mid=(l+r)/2;
    updateRange(st,en,2*i+1,l,mid,val);
    updateRange(st,en,2*i+2,mid+1,r,val);
  
    sgt[i].maxe=max(sgt[2*i+1].maxe,sgt[2*i+2].maxe);
    sgt[i].mine=min(sgt[2*i+1].mine,sgt[2*i+2].mine);
}

int query(int i,int l,int r){
     propagate(i,l,r);    
   
    if(sgt[i].maxe<0 || sgt[i].mine>0) return -1;
    if(l==r){
        return l;
    }

    int mid=(l+r)/2;
   int left=query(2*i+1,l,mid);
   if(left!=-1) return left;
    
   return query(2*i+2,mid+1,r);
}


int longestBalanced(vector<int>& arr) {
         
         int n=arr.size();
         sgt.assign(4*n,Node());
         lazy.assign(4*n,0);
         int ans=0;
   
   unordered_map<int,int>mp;
         for(int i=0;i<n;i++){
            int val=arr[i]%2==0 ? 1 : -1;

            int prev=-1;
            if(mp.find(arr[i])!=mp.end()) prev=mp[arr[i]];

            if(prev!=-1){
                updateRange(0,prev,0,0,n-1,-val);
            }

             updateRange(0,i,0,0,n-1,val);

             int left_most_zero_idx=query(0,0,n-1);
           if(left_most_zero_idx!=-1)  ans=max(ans,i-left_most_zero_idx+1);
             mp[arr[i]]=i;
         }
     return ans;
    }
};