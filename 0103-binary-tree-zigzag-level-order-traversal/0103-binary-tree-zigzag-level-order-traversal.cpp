class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;

        queue<TreeNode*>q;
        q.push(root);

        while(q.size()>0){
           int size=q.size();
           
           vector<int>lvl;
           for(int i=0;i<size;i++){
              TreeNode* node=q.front();

              if(node->left!=NULL) q.push(node->left);
              if(node->right!=NULL) q.push(node->right);

              lvl.push_back(node->val);   
              q.pop();
           }
           ans.push_back(lvl);
        }

        for(int i=1;i<ans.size();i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }
        
        return ans;
    }
};