class TrieNode {
public:
    TrieNode* children[26];
    bool isWordCompleted;

    TrieNode() {
        memset(children, 0, sizeof(children));
        isWordCompleted = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* newRoot = root;
        for (char ch : word) {
            int alphabetIndex = ch - 'a';
            if (newRoot -> children[alphabetIndex] == NULL) {
                newRoot -> children[alphabetIndex] = new TrieNode();
            } 
            newRoot = newRoot -> children[alphabetIndex];
        }
        newRoot -> isWordCompleted = true;
    }
    
    bool search(string word) {
        TrieNode* newRoot = root;
        for (char ch : word) {
            int alphabetIndex = ch - 'a';
            if (newRoot -> children[alphabetIndex] == NULL) {
                return false;
            } 
            newRoot = newRoot -> children[alphabetIndex];
        }
        if (newRoot -> isWordCompleted == true) {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* newRoot = root;
        for (char ch : prefix) {
            int alphabetIndex = ch - 'a';
            if (newRoot -> children[alphabetIndex] == NULL) {
                return false;
            } 
            newRoot = newRoot -> children[alphabetIndex];
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