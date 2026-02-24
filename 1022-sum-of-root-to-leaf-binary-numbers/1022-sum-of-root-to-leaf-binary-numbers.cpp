
class Solution {
public:
int solve(TreeNode* node,int curr){
   if(node==NULL) return 0; 
   curr=curr*2+node->val;
    if(node->left==NULL && node->right==NULL) return curr;   
   return solve(node->left,curr)+solve(node->right,curr);
}

int sumRootToLeaf(TreeNode* root) {

     
      return solve(root,0);        
    }
};