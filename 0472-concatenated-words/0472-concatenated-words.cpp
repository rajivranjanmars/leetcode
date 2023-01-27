class TrieNode {
public:
    TrieNode() {
        isEnd = false;
        children.resize(26, NULL);
    }

    bool isEnd;
    vector<TrieNode*> children;
};

class Trie {
public:
    Trie() {
        head = new TrieNode();
    }

    bool findWord(string &word) {
        bool res = isComprised(word, 0, head);
        putWord(word);
        return res;
    }

    bool isComprised(string &word, int index, TrieNode* node) {
        bool res = false;
        while (index < word.size()) {
            if (!node->children[word[index] - 'a']) {
                return (node->isEnd)? isComprised(word, index, head) : false;
            }
            if (node->isEnd && isComprised(word, index, head)) return true;
            node = node->children[word[index] - 'a'];
            index++;
        }
        return node->isEnd;
    }

    void putWord(string &word) {
        TrieNode* node = head;
        for (char c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }

private:
    TrieNode* head;
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &word1, string &word2) {return word1.size() < word2.size();});
        Trie* trie = new Trie();
        vector<string> res;
        for (auto &word : words)
            if (trie->findWord(word)) res.push_back(word);
        return res;
    }
};