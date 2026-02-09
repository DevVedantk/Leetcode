
class Solution {
public:
       vector<int>arr;

       void dfs(TreeNode* node){
        if(node==NULL) return;
        arr.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
       }

TreeNode* solve(vector<int>&arr,int lo,int hi){
   
   if(lo>hi) return NULL;
    
    int mid=(lo+hi)/2;

    TreeNode* node=new TreeNode();
    node->val=arr[mid];
    node->left=solve(arr,lo,mid-1);
    node->right=solve(arr,mid+1,hi);
    return node;
}            
TreeNode* balanceBST(TreeNode* root) {
      
      dfs(root);
     
     sort(arr.begin(),arr.end());
     int n=arr.size();
      return solve(arr,0,n-1);
    }
};