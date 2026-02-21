struct Node{
    Node* links[26];

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
         links[ch-'a']=node;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    bool insert(string& s){
        Node* node=root;
        bool flag=false;
        for(int i=0;i<s.size();i++){
           if(!node->containsKey(s[i])){
            node->put(s[i],new Node());
            flag=true;
           }
           node=node->get(s[i]);
        }
        return flag;
    }
};

class Solution {
public:
    vector<string> partitionString(string s) {
        Trie trie;
        int i=0;
        string un="";
        vector<string>ans;
        while(i<s.size()){
            un+=s[i];
           if(trie.insert(un)){
            ans.push_back(un);
            un="";
           }
           i++;  
        }
        return ans;
    }
};