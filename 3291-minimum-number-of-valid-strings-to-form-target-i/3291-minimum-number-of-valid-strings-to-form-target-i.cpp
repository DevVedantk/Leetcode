struct Node {
    Node* links[26];
    bool end = false;
    Node() {
        for (int i = 0; i < 26; i++) links[i] = NULL;
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        end = true;
    }

    bool getEnd() {
        return end;
    }
};

class Trie {
public:
    Node* root;
    vector<int>dp;

    Trie() {
        root = new Node();
    }

    void insert(string& s) {
        Node* node = root;
        for (int i = 0; i < (int)s.size(); i++) {
            if (!node->containsKey(s[i])) {
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->setEnd();
    }

    int solve(string& s, int idx) {
        if (idx >= (int)s.size()) return 0;

       if(dp[idx]!=-1) return dp[idx];

        int ans = 1e9;
        Node* node=root;

        for(int j=idx;j<s.size();j++){
          if(!node->containsKey(s[j])) break;
          node=node->get(s[j]);
          ans=min(ans,1+solve(s,j+1));
        } 

        return dp[idx]= ans;
    }

    int check(string& s) {
        dp.assign(s.size()+1,-1);
        int ans = solve(s, 0);
        if (ans == 1e9) return -1;
        return ans;
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie trie;
        for (int i=0;i<words.size();i++)
            trie.insert(words[i]);
        return trie.check(target);
    }
};
