struct Node{
    Node* links[26];
    bool ends=false;

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
    void setTrue(){
        ends=true;
    }
    bool Checkends(){
        return ends;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
          Node* node=root;
          for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
          }
          node->setTrue();
    }
    
    bool search(string word) {
         Node* node=root;
         for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
               return false;
            }
            node=node->get(word[i]);
         }
          
          return node->Checkends();

    }
    
    bool startsWith(string pre) {
         Node* node=root;
         for(int i=0;i<pre.size();i++){
            if(!node->containsKey(pre[i])){
               return false;
            }
            node=node->get(pre[i]);
         }
         return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */