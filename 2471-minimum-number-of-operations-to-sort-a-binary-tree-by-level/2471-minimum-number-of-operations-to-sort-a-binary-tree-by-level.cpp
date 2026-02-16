
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        vector<vector<int>>ans;

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

        int cnt=0;

        for(int i=0;i<ans.size();i++){
            vector<int>arr=ans[i];
            sort(arr.begin(),arr.end());

           map<int,int>mp;
            for(int j=0;j<arr.size();j++) mp[arr[j]]=j;

             int j=0; 
             while(j<ans[i].size()){
               if(mp[ans[i][j]]==j) j++;
               else {
                cnt++;
                int correctIdx=mp[ans[i][j]];
                swap(ans[i][j],ans[i][correctIdx]);
               }
             }
        }
        return cnt;
    }
};