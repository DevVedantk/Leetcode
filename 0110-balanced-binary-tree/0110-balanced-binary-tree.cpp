class Solution {
public:
bool ans;
int solve(TreeNode* node){
     if(node==NULL) return 0;
    int h1=solve(node->left);
    int h2=solve(node->right);
    if(abs(h1-h2)>1) ans=false;

    return 1+max(h1,h2);
}
    bool isBalanced(TreeNode* root) {
        ans=true;
       solve(root);  
       return ans;      
    }
};