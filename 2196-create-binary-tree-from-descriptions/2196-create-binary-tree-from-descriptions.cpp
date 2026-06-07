/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

TreeNode* solve(map<int,vector<int>>&mp,TreeNode* node){
      if(mp[node->val][0]==-1 && mp[node->val][1]==-1){
        return node;
      }

     if(mp[node->val][0]!=-1){
       node->left = new TreeNode(mp[node->val][0]);
       solve(mp, node->left);
     }
     if(mp[node->val][1]!=-1) {
        node->right= new TreeNode(mp[node->val][1]);
       solve(mp, node->right);
     }

     return node;

}
    TreeNode* createBinaryTree(vector<vector<int>>& arr) {
            map<int,vector<int>>mp;
            set<int>st;
            
            for(int i=0;i<arr.size();i++){
                st.insert(arr[i][1]);
                st.insert(arr[i][0]);
                mp[arr[i][0]]=vector<int>(2,-1);
                mp[arr[i][1]]=vector<int>(2,-1);
            }

            for(int i=0;i<arr.size();i++){
                if(arr[i][2]==1){
                    mp[arr[i][0]][0]=arr[i][1]; //left child
                    st.erase(arr[i][1]);
                } else{
                     mp[arr[i][0]][1]=arr[i][1]; // right child
                     st.erase(arr[i][1]);
                }
            }
            
            TreeNode* node=new TreeNode(*st.begin());
            // return node;
            return solve(mp,node);

    }
};