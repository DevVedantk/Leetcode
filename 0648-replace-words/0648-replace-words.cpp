struct Node{
   Node* links[26];
   bool ends=false;

   bool containsKey(char ch){
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

    bool getEnd(){
        return ends;
    }
   
};

class Trie{
    public:
    Node* root;
   Trie(){
    root=new Node();
   }

 
   void insert(string& s){
      Node* node=root;
      for(int i=0;i<s.size();i++){
        if(!node->containsKey(s[i])){
            node->put(s[i],new Node());
        }
        node=node->get(s[i]);
      }
      node->setEnd();
   }

   string check(string& s){
    Node* node=root;
    int i=0;
    for(i=0;i<s.size();i++){
        if(!node->containsKey(s[i])){
          break;
        }
      if(node->getEnd()) return s.substr(0,i);
       node=node->get(s[i]);
    }
    if(node->getEnd()) return s.substr(0,i);
    return "";

   }
    
   
    

};

class Solution {
public:
    string replaceWords(vector<string>& dic, string s) {
        Trie trie;
        for(int i=0;i<dic.size();i++){
            trie.insert(dic[i]);
        }
        int i=0,j=0;
        string ans="";
        while(j<s.size()){
            if(s[j]!=' ') j++;
            else{
                string sub=s.substr(i,j-i);
                string pref=trie.check(sub);
                if(pref!="") ans+=pref+' ';
                else ans+=sub+' ';
                i=j+1;
                j=i;
            }
        }

          string sub=s.substr(i,j-i);
                string pref=trie.check(sub);
                if(pref!="") ans+=pref;
                else ans+=sub;
      return ans;
        
    }
};