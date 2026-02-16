
class Solution {
public:
int solve(TreeNode* node){
    if(node->left==NULL && node->right==NULL) return 0;
    int ans=1e9;
    // int left,right;
    if(node->left!=NULL) ans=min(ans,1+solve(node->left));
    if(node->right!=NULL) ans=min(ans,1+solve(node->right));

   return ans;
}
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
      return solve(root)+1;        
    }
};