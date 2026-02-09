class NumArray {
public:
vector<int>fen;
vector<int>arr;
int n;

void updateFen(int idx,int x){
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

NumArray(vector<int>& nums) {
       n=nums.size();
        arr=nums;
        fen.assign(n+1,0);
       
       for(int i=1;i<=nums.size();i++){
          updateFen(i,nums[i-1]);
       }
    }
    
    void update(int index, int val) {
        int diff=val-arr[index];
        arr[index]=val; 
        updateFen(index+1,diff);   

    }
    
    int sumRange(int left, int right) {
        
        return (sum(right+1)-sum(left));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */