class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            int size=q.size();
             
             vector<int>lvl;
            for(int i=0;i<size;i++){
             TreeNode* node=q.front();
             q.pop();
             lvl.push_back(node->val);

            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
        ans.push_back(lvl);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;        
    }
};