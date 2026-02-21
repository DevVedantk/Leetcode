struct Node{
   Node* links[26];
   bool end=false;

  void put(char ch,Node* node){
     links[ch-'a']=node;
  }

  Node* get(char ch){
    return links[ch-'a'];
  }

  bool containsKey(char ch){
    return (links[ch-'a']!=NULL);
  }

  void setEnd(){
    end=true;
  }

  bool getend(){
    return end;
  }
};

class Trie{
   public:
   Node* root;
   
   Trie(){
    root=new Node();
   }
  void insert(string& s){
    reverse(s.begin(),s.end());

    Node* node=root;
    for(int i=0;i<s.size();i++){
        if(!node->containsKey(s[i])){
            node->put(s[i],new Node());
        }
       node=node->get(s[i]);
    }
    node->setEnd();
  }

  bool check(string& s){
    Node* node=root;
    
    for(int i=s.size()-1;i>=0;i--){
        if(!node->containsKey(s[i])) return false;
         node=node->get(s[i]);
         if(node->getend()) return true;
    }
     
    return false;
  }
};

class StreamChecker {
public:
        Trie trie;
        string s="";
    StreamChecker(vector<string>& words) {
        // Trie trie;
        for(int i=0;i<words.size();i++){
            trie.insert(words[i]);
        }
    }
    
    bool query(char letter) {
        s+=letter;
        return trie.check(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */