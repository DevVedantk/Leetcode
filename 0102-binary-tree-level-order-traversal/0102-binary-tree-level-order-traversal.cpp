class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>>ans;
       if(root==NULL) return ans;
       queue<TreeNode*>q;
        
        q.push(root);
       while(q.size()>0){
          int size=q.size();
          vector<int>lvl;
          for(int i=0;i<size;i++){
          TreeNode* node=q.front();
               
               if(node!=NULL && node->left!=NULL) q.push(node->left);
               if(node!=NULL && node->right!=NULL) q.push(node->right);

             if(node!=NULL)  lvl.push_back(node->val);
               q.pop();
          }
          ans.push_back(lvl);
       }
       
       return ans;
    }
};