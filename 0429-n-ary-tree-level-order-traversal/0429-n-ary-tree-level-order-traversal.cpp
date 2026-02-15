/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        
        queue<Node*>q;
        q.push(root);
        while(q.size()>0){
          int size=q.size();
          vector<int>lvl;
          for(int i=0;i<size;i++){
                  Node* node=q.front();    
              lvl.push_back(node->val);
              q.pop();
              for(Node* child:node->children) q.push(child);
            }       
          ans.push_back(lvl);
          }
        return ans;
        }
};