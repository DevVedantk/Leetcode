struct Node{
  Node* links[26];
  vector<int> idxs;

  Node* get(char ch){
    return links[ch-'a'];
  }
   
   void put(char ch,Node* node){
     links[ch-'a']=node;
   }
   bool containsKey(char ch){
    return (links[ch-'a']!=NULL);
   }

   vector<int> indexes(){
    return idxs;
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
     
     for(int i=0;i<s.size();i++){
        if(!node->containsKey(s[i])){
            node->put(s[i],new Node());
        }
        node=node->get(s[i]);
            node->idxs.push_back(idx);
     }

   }

   vector<int>& checkPre(string pref){
    Node* node=root;
    for(int i=0;i<pref.size();i++){
        if(!node->containsKey(pref[i])){
             static vector<int> empty;
                return empty;
        }
        node=node->get(pref[i]);
    }
    return node->idxs;
   }
};


class WordFilter {
public:
    Trie trie;
    vector<string>strs;
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            trie.insert(words[i],i);
        }
        strs=words;
    }
    
    int f(string pref, string suff) {
         vector<int>& idxs=trie.checkPre(pref);
            for(int i=idxs.size()-1;i>=0;i--){
                string s=strs[idxs[i]];
                int n=s.size();
               if(s.size()>=suff.size() && s.compare(n-suff.size(),suff.size(),suff)==0)
               return idxs[i];
            }
         
     return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */