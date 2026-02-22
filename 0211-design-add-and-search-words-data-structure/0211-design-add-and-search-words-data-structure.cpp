struct Node{
    Node* links[26];
    bool ends=false;

    bool containsKey(char ch){
        if(ch=='.') return false;
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        ends=true;
    }
    
    bool checkEnd(){
         return ends;
    }
    

    Node* matchOneByOne(){
        for(int i=0;i<26;i++){
            if(links[i]!=NULL) return links[i];
        }
        return NULL;
    }  
};
class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root=new Node();
    }

    bool solve(string& s,int idx,Node* node){
        if(node==NULL) return false;
        if(idx>=s.size()) return node->checkEnd();
        bool ans=false;

        if(s[idx]=='.'){
            for(int i=0;i<26;i++){
                ans=ans|solve(s,idx+1,node->links[i]);
            }
        } else{
            if(!node->containsKey(s[idx])) return false;
            ans=ans|solve(s,idx+1,node->get(s[idx]));
        }
        return ans;
    }
    
    void addWord(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        return solve(word,0,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */