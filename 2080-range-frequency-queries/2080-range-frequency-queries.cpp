class RangeFreqQuery {
public:

struct Node{
  int cnt=0;
  Node* left=NULL;
  Node* right=NULL;
};
int mx=0;

Node* buildt(int l,int r){
    if(l==r){
        Node* leaf=new Node();
        leaf->cnt=0;
        return leaf;
    }
    int mid=(l+r)/2;
    Node* res=new Node();
    res->left=buildt(l,mid);
    res->right=buildt(mid+1,r);
   
   return res;  
}

Node* update(int l,int r,Node* past,int idx){
    if(l==r){
       Node* leaf=new Node();
       leaf->cnt=1+past->cnt;  
       return leaf;
    }

    int mid=(l+r)/2;
    Node* res=new Node();
    if(idx<=mid){
        res->left=update(l,mid,past->left,idx);
        res->right=past->right;
    } else{
         res->left=past->left;
        res->right=update(mid+1,r,past->right,idx);
    }
    res->cnt=(res->left->cnt+res->right->cnt);
    return res;
}

int query(int l,int r,Node* prev,Node* curr,int idx){
    if(idx>mx) return 0;
    if(l==r){
        if(l>mx||r>mx) return 0;
        return (curr->cnt-prev->cnt);
    }

    int mid=(l+r)/2;
    if(idx<=mid) return query(l,mid,prev->left,curr->left,idx);
    else return query(mid+1,r,prev->right,curr->right,idx);
}

vector<Node*>states;
RangeFreqQuery(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++) mx=max(mx,arr[i]);

        states.push_back(buildt(0,mx));

        for(int i=0;i<n;i++){
            int size=states.size();
            Node* prev=states[size-1];
            states.push_back(update(0,mx,prev,arr[i]));
        }
    }
    
    int query(int left, int right, int value) {

        Node* prev=states[left]; 
        Node* curr=states[right+1];
      return query(0,mx,prev,curr,value);
        // return freq<=0 ? 0:freq; 
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */