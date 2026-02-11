class Solution {
public:

long long sgt[500001][2][2];
const long long NEG = -1e9;   // or LLONG_MIN/4


void buildt(int i,int l,int r,vector<int>&arr){
    
    if(l==r){
        sgt[i][0][0]=0;
        sgt[i][1][1]=(long long)arr[l];
        sgt[i][1][0]=sgt[i][0][1]=NEG;
        return;
    }

    int mid=(l+r)/2;
    buildt(2*i+1,l,mid,arr);
    buildt(2*i+2,mid+1,r,arr);
     
     int left=2*i+1,right=2*i+2;
    sgt[i][0][0]=max({sgt[left][0][0]+sgt[right][1][0],sgt[left][0][0]+sgt[right][0][0],sgt[left][0][1]+sgt[right][0][0]});
    sgt[i][0][1]=max({sgt[left][0][0]+sgt[right][1][1],sgt[left][0][0]+sgt[right][0][1],sgt[left][0][1]+sgt[right][0][1]});
    sgt[i][1][0]=max({sgt[left][1][0]+sgt[right][1][0],sgt[left][1][0]+sgt[right][0][0],sgt[left][1][1]+sgt[right][0][0]});
    sgt[i][1][1]=max({sgt[left][1][0]+sgt[right][1][1],sgt[left][1][0]+sgt[right][0][1],sgt[left][1][1]+sgt[right][0][1]});
}

void update(int i,int l,int r,int idx,int val){


     if(l==r){
        sgt[i][0][0]=0;
        sgt[i][1][1]=(long long)val;
        sgt[i][1][0]=sgt[i][0][1]=NEG;
        return;
    }

    int mid=(l+r)/2;
   if(idx<=mid) update(2*i+1,l,mid,idx,val);
   else update(2*i+2,mid+1,r,idx,val);

     int left=2*i+1,right=2*i+2;
    sgt[i][0][0]=max({sgt[left][0][0]+sgt[right][1][0],sgt[left][0][0]+sgt[right][0][0],sgt[left][0][1]+sgt[right][0][0]});
    sgt[i][0][1]=max({sgt[left][0][0]+sgt[right][1][1],sgt[left][0][0]+sgt[right][0][1],sgt[left][0][1]+sgt[right][0][1]});
    sgt[i][1][0]=max({sgt[left][1][0]+sgt[right][1][0],sgt[left][1][0]+sgt[right][0][0],sgt[left][1][1]+sgt[right][0][0]});
    sgt[i][1][1]=max({sgt[left][1][0]+sgt[right][1][1],sgt[left][1][0]+sgt[right][0][1],sgt[left][1][1]+sgt[right][0][1]});
}

    int maximumSumSubsequence(vector<int>& arr, vector<vector<int>>& q) {
         
         long long ans=0;
         int n=arr.size();
         int MOD=1e9+7;

         buildt(0,0,n-1,arr);
         long long x=max({sgt[0][0][0],sgt[0][1][0],sgt[0][0][1],sgt[0][1][1]});;

         for(int i=0;i<q.size();i++){
            update(0,0,n-1,q[i][0],q[i][1]);
            x=max({sgt[0][0][0],sgt[0][1][0],sgt[0][0][1],sgt[0][1][1]});
            //  x=x%MOD;
           ans = (ans + x);
             ans=ans%MOD;

         }
     
     return ans;
    }
};