
class Solution {
public:
    int maxLevelSum(TreeNode* root) {

           queue<TreeNode*>q;
           q.push(root);
           int ans=1;
      
            
            int level=0;
            int maxs=-1e9;
        while(q.size()>0){
           int size=q.size();
           int sum=0;
           level++;
           for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
          
          if(node!=NULL)   sum+=node->val;

           if(node!=NULL && node->right!=NULL) q.push(node->right);
           if(node!=NULL && node->left!=NULL) q.push(node->left);
           }
       if(maxs<sum){
        maxs=sum;
        ans=level;
       }
        }
                  return ans;  
    }
};