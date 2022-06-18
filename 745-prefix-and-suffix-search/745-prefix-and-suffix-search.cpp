class node{
    
    public:
    
    char c;
    int lastEle;
    vector<node*> children;
    
    node(char C = ' '){
        this->c = C;
        this-> lastEle =0;
        children.resize(27,NULL);
    }
    
};


class WordFilter {
public:
    node* Root;
    
    
    void insert(string& word, int idx){
        
        int n = word.size();
        int i=0; 
        node* curr = this->Root;
        
        while(i < n){
            
            char c = word[i];
            
            if(curr->children[c-'a']==NULL)
                curr->children[c-'a'] = new node(c);
            
            curr->children[c-'a']->lastEle = idx;
            
            curr = curr-> children[c-'a'];
            
            i++;
        }
        
        return; 
    }
    
    WordFilter(vector<string>& words) {
        this->Root = new node;
        
        int ws = words.size();
        
        for(int j=0;j<ws;j++){
            
            string word = words[j];
            int n = word.length();
            string suffix = "";
            
            for(int i=n-1;i > -1;i--){
                suffix = word[i] + suffix;
                string stringToInsert = suffix + '{' + word;
               
                insert(stringToInsert, j);
            }
            
        }
        
    }
    
    
    
    int searchInTrie(string& word){
        int n = word.length();
        int i = 0;
        node* curr = this->Root;
        
        while(curr && i < n){
            
            char c = word[i];
            
            curr = curr->children[c-'a'];
             
            i++;
        }
        
        if(curr==NULL) return -1;
        
        else return curr->lastEle; 
        
    }
    
    int f(string prefix, string suffix) {
        
        string wordToSearch = suffix + '{' + prefix;

        return searchInTrie(wordToSearch);
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */