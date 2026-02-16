class Solution {
public:

void solve(TreeNode* leftchild,TreeNode* rightchild,int lvl){
   if(leftchild==NULL || rightchild==NULL) return;

   if(lvl%2==0){
  swap(leftchild->val,rightchild->val);
   }

   solve(leftchild->left,rightchild->right,lvl+1);
   solve(leftchild->right,rightchild->left,lvl+1);
}
    TreeNode* reverseOddLevels(TreeNode* root) {

         solve(root->left,root->right,0);  
         return root;    
    }
};