struct Node {
    Node* links[26];
    bool end = false;

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    bool getEnd() {
        return end;
    }

    void setEnd() {
        end = true;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string& s) {
        Node* node = root;
        for (char c : s) {
            if (!node->containsKey(c)) {
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
    }

    bool check(string& s) {
        Node* node = root;
        for (char c : s) {
            if (!node->containsKey(c)) return false;
            node = node->get(c);
        }
        return node->getEnd();
    }

    
};

class Encrypter {
public:
    map<char, string> mp1;
    map<string, vector<char>> mp2;
    Trie trie;

    Encrypter(vector<char>& keys, vector<string>& val, vector<string>& dic) {
        for (int i = 0; i < keys.size(); i++) {
            mp1[keys[i]] = val[i];
            mp2[val[i]].push_back(keys[i]);
        }

        for (auto& word : dic) trie.insert(word);
    }

    string encrypt(string word1) {
        string ans = "";
        for (char c : word1)
            if (mp1.count(c)) ans += mp1[c];
        return ans;
    }

    int allstrs(string& s, int idx, Node* node) {
        if (idx >= s.size()) {
            return node->getEnd();
        }
         
        if (idx + 1 >= s.size()) return 0;
         int cnt=0;

        string sub = s.substr(idx, 2); 
        if (!mp2.count(sub)) return 0;

        for (char c : mp2[sub]) {
            if(node->containsKey(c)){
           cnt+=allstrs(s,idx + 2,node->get(c));
            }
        }
        return cnt;
    }

    int decrypt(string word2) {
   
       return allstrs(word2, 0,trie.root);
    
    }
};
