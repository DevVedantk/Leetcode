class Solution {
public:

struct Node{
  int firstsum=0;
  int secondsum=0;
};

vector<int>lazy;
vector<Node>sgt;
int MOD=1e9+7;
Node merge(const Node&left,const Node&right){
    Node res;

    res.firstsum=(left.firstsum+right.firstsum)%MOD;
    res.secondsum=(left.secondsum+right.secondsum)%MOD;
    return res;
}

void buildt(int i,int l,int r){
    if(l==r){
        sgt[i].firstsum=0;
        sgt[i].secondsum=0;
        return;
    }

    int mid=(l+r)/2;
    buildt(2*i+1,l,mid);
    buildt(2*i+2,mid+1,r);
    sgt[i]=merge(sgt[2*i+1],sgt[2*i+2]);
}

void propogate(int i,int l,int r){
    if(lazy[i]!=0){
        int len=r-l+1;
        sgt[i].secondsum=( sgt[i].secondsum + (2*sgt[i].firstsum*lazy[i])%MOD + (len*lazy[i]*lazy[i])%MOD)%MOD;
        sgt[i].firstsum=(sgt[i].firstsum+(len*lazy[i])%MOD)%MOD;
        if(l!=r){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
}


void update(int i,int l,int r,int st,int en,int x){
  propogate(i,l,r);
  if(st>r || l>en) return;
  if(l>=st && r<=en){
    lazy[i]+=x;
     propogate(i,l,r);
     return;
  }

  int mid=(l+r)/2;

  update(2*i+1,l,mid,st,en,x);
  update(2*i+2,mid+1,r,st,en,x);

   sgt[i]=merge(sgt[2*i+1],sgt[2*i+2]);
}

Node query(int i,int l,int r,int st,int en){
    propogate(i,l,r);
    if(st>r || l>en) return Node();
    if(l>=st && r<=en) return sgt[i];

    int mid=(l+r)/2;

   Node left=query(2*i+1,l,mid,st,en);
   Node right=query(2*i+2,mid+1,r,st,en);

   return merge(left,right);
}


int sumCounts(vector<int>& arr) {
         
         int n=arr.size();

         lazy.assign(4*n,0);
         sgt.assign(4*n,Node());

         buildt(0,0,n-1);

         map<int,int>mp;
         
         int ans=0;
         for(int i=0;i<n;i++){
            int prev=-1;

            if(mp.find(arr[i])!=mp.end()){
                prev=mp[arr[i]];
            }
            update(0,0,n-1,prev+1,i,1);
            Node q_ans=query(0,0,n-1,0,i);
            ans=(ans+q_ans.secondsum)%MOD;
            mp[arr[i]]=i;
         }
         return ans;
    }
};