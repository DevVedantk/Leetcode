class Solution {
public:
vector<int>sgt;

void update(int i,int l,int r,int idx){
   if(l==r){
    sgt[i]+=1;
    return;
   }

   int mid=(l+r)/2;
   if(idx<=mid) update(2*i+1,l,mid,idx);
   else update(2*i+2,mid+1,r,idx);

   sgt[i]=sgt[2*i+1]+sgt[2*i+2];
}
int query(int st,int en,int i,int l,int r){
  if(st>r || l>en) return 0;
  if(l>=st && r<=en) return sgt[i];

  int mid=(l+r)/2;

  int left=query(st,en,2*i+1,l,mid);    
  int right=query(st,en,2*i+2,mid+1,r);

  return left+right;    
    
}

long long countMajoritySubarrays(vector<int>& arr, int target) {
         
         int n=arr.size();

        for(int i=0;i<n;i++){
            if(arr[i]==target) arr[i]=1;
            else arr[i]=-1;
        }
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        map<int,int>mp;
        for(int i=0;i<n;i++) mp[arr[i]];
        mp[0];
        
        int cnt=1;
        for(auto &ele:mp){
            ele.second=cnt;
            cnt++;
        }
        
        for(int i=0;i<n;i++) arr[i]=mp[arr[i]];
        
        sgt.assign(4*cnt,0);

         long long ans=0;

            update(0,0,cnt-1,mp[0]);

         for(int i=0;i<n;i++){
            int q_ans=query(0,arr[i]-1,0,0,cnt-1);

            ans+=q_ans;
            update(0,0,cnt-1,arr[i]);
         }
         return ans;
        
    }
};