class WordDictionary {
public:
    
    struct Node
    {
        Node* arr[26];
        bool isend=false;
    };
    
    Node* root;

    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        
        Node* temp=root;
        
        for(auto x:word)
        {
            if(root->arr[x-'a']==NULL)
                root->arr[x-'a']=new  Node();
           root= root->arr[x-'a'];
        }
        root->isend=true;
        root=temp;
    }
    
    
    
    bool find(string& word,Node* root,int i)
    {
        if(i>=word.size()&&root->isend)
            return 1;
        if(i>=word.size())
            return 0;
        
        if(!root)
            return 0;
         
        
        if(word[i]!='.')
        {
            if(root->arr[word[i]-'a'])
                return find(word,root->arr[word[i]-'a'],i+1);
            else 
                return 0;
        }
        else
        {
            int a=0;
            for(int i1=0;i1<26;i1++)
            {
                if(root->arr[i1])
                    a|=find(word,root->arr[i1],i+1);
            }
            return a;
        }
        return 0;
    }
    
    
    bool search(string word) {
        return find(word,root,0);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */