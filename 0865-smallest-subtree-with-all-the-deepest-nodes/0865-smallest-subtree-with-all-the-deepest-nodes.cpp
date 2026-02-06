
class Solution {
public:
int ht(TreeNode* node){
    int lvl=1;
    if(node==NULL) return 0;
    lvl=max(lvl,1+ht(node->left));
    lvl=max(lvl,1+ht(node->right));

    return lvl;
}
vector<TreeNode*>arr;

void depth(TreeNode* node,int lvl,int depest){
   if(node==NULL) return;
   if(lvl==depest) arr.push_back(node);
   depth(node->left,lvl+1,depest);
   depth(node->right,lvl+1,depest);
}  
 bool check(TreeNode* root,TreeNode* node){
        if(root==NULL) return false;
        if(root==node) return true;
       return (check(root->left,node) || check(root->right,node));
    }
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==root ||  q==root) return root;
        // if(p==null || q==null) return 
        bool plst=check(root->left,p);  
        bool qlst=check(root->left,q);
        if((plst==false && qlst==false)) return lowestCommonAncestor(root->right,p,q);
        if((plst==true && qlst==true)) return lowestCommonAncestor(root->left,p,q);
          return root; 
    } 

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
         
        //  cout << ht(root) << endl;
        int depest=ht(root);
         depth(root,1,depest);
         if(arr.size()==1) return arr[0];
        // lowestCommonAncestor(

        TreeNode* lca=lowestCommonAncestor(root,arr[0],arr[1]); 
        TreeNode* ans=lca;
        for(int i=2;i<arr.size();i++){
            ans=lowestCommonAncestor(root,ans,arr[i]);
        }

        return ans;
    }
};