class Node {
public:
    int key,value,count;
    Node *next, *prev;
    Node(int _key, int _value)
    {
        key=_key;
        value=_value;
        count=1;
    }
};
class List {
public:
    Node *head, *tail;
    int size;
    List()
    {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size=0;
    }
    void insertNode(Node *node)
    {
        Node *nextNode = head->next;
        head->next = node;
        node->next = nextNode;
        nextNode->prev = node;
        node->prev = head;
        size++;
    }
    void deleteNode(Node *node)
    {
        Node *nextNode = node->next;
        Node *prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
        size--;
    }
};

class LFUCache {
public:
    unordered_map<int,Node*> keyNode;
    unordered_map<int,List*> freqList;
    int maxSize,curSize,minFreq;
    LFUCache(int capacity) {
        maxSize=capacity;
        minFreq=0;
        curSize=0;
    }
    
    void updateFreqList(Node *node)
    {
        List *fList = freqList[node->count];
        fList->deleteNode(node);
        if(minFreq==node->count && fList->size==0)
            minFreq++;
        node->count++;
        List *nextHigherFreqList = new List();
        if(freqList.find(node->count)!=freqList.end())
            nextHigherFreqList = freqList[node->count];
        nextHigherFreqList->insertNode(node);
        freqList[node->count]=nextHigherFreqList;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqList(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSize==0)
            return;
        if(keyNode.find(key)!=keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        }
        else
        {
            if(curSize==maxSize)
            {
                List *list = freqList[minFreq];
                int k = list->tail->prev->key;
                list->deleteNode(list->tail->prev);
                keyNode.erase(k);
                curSize--;
            }
            curSize++;
            minFreq=1;
            List *l = new List();
            if(freqList.find(minFreq)!=freqList.end())
            {
                l=freqList[minFreq];
            }
            Node *n = new Node(key,value);
            l->insertNode(n);
            keyNode[key]=n;
            freqList[minFreq]=l;
        }
    }
};