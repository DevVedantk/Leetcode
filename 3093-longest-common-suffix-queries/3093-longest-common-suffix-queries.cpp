struct Node{
    Node* links[26];
    vector<int>idxs;

  bool containsKey(char ch){
    return (links[ch-'a']!=NULL);
  }

  void put(char ch,Node* node){
    links[ch-'a']=node;
  }

  Node* get(char ch){
    return links[ch-'a'];
  }

};

class Trie{
 public:
 Node* root;
 Trie(){
    root=new Node();
 }

    void insert(string& s,int idx){
      Node* node=root;
      for(int i=s.size()-1;i>=0;i--){
        if(!node->containsKey(s[i])){
            node->put(s[i],new Node());
        }
        node=node->get(s[i]);
        node->idxs.push_back(idx);
      }
    }

  vector<int>& check(string& s) {
    Node* node = root;
    Node* lastValid = root;  // track last node that existed
    for (int i = s.size() - 1; i >= 0; i--) {
        if (!node->containsKey(s[i])) {
            return lastValid->idxs;
        }
        node = node->get(s[i]);
        lastValid = node;
    }
    return node->idxs; 
}

  void deleteNode(Node* node) {
        if (!node) return;
        for (int i = 0; i < 26; i++) {
            if (node->links[i]) deleteNode(node->links[i]);
        }
        delete node;
    }

    void clear() {
        deleteNode(root);
        root = nullptr;
    }

};

class Solution {
public:
    vector<int> stringIndices(vector<string>& word, vector<string>& q) {
        Trie trie;
        int small=0;
        string s=word[0];
        for(int i=0;i<word.size();i++){
        trie.insert(word[i],i);
         if(word[i].size()<s.size()){
            small=i;
            s=word[i];
         }
        }

        vector<int>ans(q.size());
      
        for(int i=0;i<q.size();i++){

           vector<int>& idxs=trie.check(q[i]);


           if(idxs.size()==0) ans[i]=small;
           else{
            string s=word[idxs[0]];
            int sm=idxs[0];
            for(int j=0;j<idxs.size();j++){
              if(s.size()>word[idxs[j]].size()){
                sm=idxs[j];
                s=word[idxs[j]];
              }    
             }
             ans[i]=sm;
           }
        }
        trie.clear();

        return ans;
    }
};