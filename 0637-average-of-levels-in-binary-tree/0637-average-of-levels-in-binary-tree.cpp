class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
       vector<double>ans;

       queue<TreeNode*>q;
       q.push(root);

       while(q.size()>0){
         int size=q.size();
         
         long long sum=0;
         for(int i=0;i<size;i++){
           TreeNode* node=q.front();
           q.pop();

           if(node->left!=NULL) q.push(node->left);
           if(node->right!=NULL) q.push(node->right);
           sum+=node->val;
         }
         double avg=(double)sum/size;       
         
         ans.push_back(avg);
       }

       return ans;

    }
};