class Solution {
public:
    struct TrieNode{
        unordered_map <char, TrieNode*> children;
        bool endofword;
        string word = "";
    };
    
    TrieNode* getNewNode(){
        TrieNode *new_node= new TrieNode();
        new_node->endofword=false;
        return new_node;
    }
    
    void insertInTrie(string s, TrieNode **root){
        if(*root==NULL) *root= getNewNode();
        TrieNode* ptr= *root;
        for(int i=0;i<s.length();i++){
            if(ptr->children.find(s[i])==ptr->children.end()){
                ptr->children[s[i]]=getNewNode();
            }
            ptr= ptr->children[s[i]];
        }
        ptr->endofword=true;   
        ptr->word=s;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode *root, vector <string> &res){
        char c= board[i][j];
        if(c=='#' || root->children.find(c)==root->children.end()) return;
        
        root = root->children[c];
        
        board[i][j]= '#';
        if(root->endofword==true) root->endofword=false, res.push_back(root->word);
        
        if (i > 0) dfs(board, i - 1, j, root, res);
        if (j > 0) dfs(board, i, j - 1, root, res);
        if (i < board.size() - 1) dfs(board, i + 1, j, root, res);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, root, res);
        board[i][j] = c;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *head= NULL;
        vector <string> res;
        int m= board.size();
        int n= board[0].size();
        for(int i=0;i<words.size();i++){
            insertInTrie(words[i], &head);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board, i, j, head, res);
            }
        }
        return res;
    }
};