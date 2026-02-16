class Solution {
public:
TreeNode* solve(TreeNode* node,int val,int targetlvl,int currlvl){
    if(node==NULL) return NULL;
     if(currlvl==targetlvl-1){
        TreeNode* nodeleft=new TreeNode(val);
        TreeNode* noderight=new TreeNode(val);
        
        nodeleft->left=node->left;
        noderight->right=node->right;
        node->left=nodeleft;   
        node->right=noderight;
        return node;   
     }

     solve(node->left,val,targetlvl,currlvl+1);
     solve(node->right,val,targetlvl,currlvl+1);
    return node;
}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
        TreeNode* nodeleft=new TreeNode(val); 
        nodeleft->left=root;
        return nodeleft;
        }
        
        return solve(root,val,depth,1);
    }
};