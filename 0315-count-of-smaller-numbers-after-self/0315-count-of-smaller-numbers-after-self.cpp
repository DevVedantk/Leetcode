class Solution {
public:
vector<int>fen;

void update(int idx,int x,int n){
    while(idx<=n){
      fen[idx]+=x;
      idx+=(idx&-idx);
    }
}

int sum(int idx){
    int s=0;
    while(idx>0){
        s+=fen[idx];
        idx-=(idx&-idx);
    }
    return s;
}

vector<int> countSmaller(vector<int>& nums) {
       set<int>st;

       for(int ele:nums) st.insert(ele);
       
       map<int,int>mp;

       int cnt=1;
       for(int ele:st){
        mp[ele]=cnt;
        cnt++;
       }
       for(int i=0;i<nums.size();i++) nums[i]=mp[nums[i]];

       int maxe=0;
       for(int ele:nums) maxe=max(maxe,ele);

       reverse(nums.begin(),nums.end());
       
       int n=nums.size();
       vector<int>ans(n);
       fen.assign(maxe+1,0);

       map<int,int>mp2;

       for(int i=0;i<n;i++){
        int cnt=sum(maxe)-sum(nums[i]);
     
        ans[i]=i-cnt-(mp2[nums[i]]);
        update(nums[i],1,maxe);
        mp2[nums[i]]++;
       }
       reverse(ans.begin(),ans.end());
       return ans;

    }
};