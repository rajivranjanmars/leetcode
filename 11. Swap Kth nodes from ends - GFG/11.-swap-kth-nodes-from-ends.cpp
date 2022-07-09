// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int n, int k)
{
    // Your Code here
   if(n%2==1 && k==(n+1)/2){
       return head;
   }
   if(k>n){
       return head;
   }
   Node* l=head,*u=head;
   Node* lp=NULL,*up=NULL;
    if(k==n){
       k=1;
   }
   if(n%2==0 && k==(n/2)+1){
       k--;
   }
   int a=k;
   int b=n-k;
   while(a>1){
       lp=l;
       l=l->next;
       a--;
   }
   while(b>0){
       up=u;
       u=u->next;
       b--;
   }
   if(u->next == NULL ){
       u->next=l->next;
       l->next=NULL;
       up->next=l;
       return u;
   }
   if(l->next == u){
       l->next=u->next;
       u->next=l;
       lp->next=u;
       return head;
   }
   Node* temp=l->next;
   Node* temp2=u->next;
   u->next=NULL;
   up->next=l;
   lp->next=u;
   u->next=temp;
   l->next=temp2;
   return head;

}
