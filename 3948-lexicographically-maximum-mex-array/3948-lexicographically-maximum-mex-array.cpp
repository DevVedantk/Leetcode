class Solution {
public:


struct Node{
    int mn;
    Node* left;
    Node* right;

    Node(){
        mn = -1;   // for 0-based indexing
        left = NULL;
        right = NULL;
    }
};

vector<Node*> all;

Node* buildt(int l,int r){
    Node* node=new Node();

    if(l==r){
        node->mn=-1;
        return node;
    }

    int mid=(l+r)/2;

    node->left=buildt(l,mid);
    node->right=buildt(mid+1,r);

    node->mn=min(node->left->mn,node->right->mn);

    return node;
}

Node* update(int idx,int l,int r,int pos,Node* last){

    if(l==r){
        Node* leaf=new Node();
        leaf->mn=pos;
        return leaf;
    }

    Node* node=new Node();

    int mid=(l+r)/2;

    if(idx<=mid){

        node->left=update(idx,l,mid,pos,last->left);
        node->right=last->right;

    }else{

        node->left=last->left;
        node->right=update(idx,mid+1,r,pos,last->right);
    }

    node->mn=min(node->left->mn,node->right->mn);

    return node;
}

int mex_query(Node* root,int l,int r,int L){

    if(l==r) return l;

    int mid=(l+r)/2;

    if(root->left->mn < L)
        return mex_query(root->left,l,mid,L);

    return mex_query(root->right,mid+1,r,L);
}

    vector<int> maximumMEX(vector<int>& arr) {
          int n=arr.size();


          Node* root=buildt(0,n);

    all.push_back(root);

    // 0-based indexing
    for(int i=0;i<n;i++){

        Node* curr=all.back();

        if(0<=arr[i] && arr[i]<=n)
            curr=update(arr[i],0,n,i,curr);

        all.push_back(curr);
    }

    vector<int> ans;

    int i=0;
      
       while(i<n){

        int lo=i,hi=n-1;

        int mex=INT_MIN;
        int idx=-1;
        
         int target_mex=mex_query(all[n],0,n,i);

        while(lo<=hi){

            int mid=(lo+hi)/2;

            int R=mid+1;
            int L=i;

           int get_mex=mex_query(all[R],0,n,L);

            if(get_mex==target_mex){
                idx=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }

        ans.push_back(target_mex);
        i=(idx+1);
    }

    return ans;
    }
};