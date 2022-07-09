// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


 // } Driver Code Ends
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */


Node* merge(Node* first, Node* second){
   
   Node* ans=NULL;
   if(first == NULL){
       return second;
   }
   if(second == NULL){
       return first;
   }
   if(first->data<=second->data){
       ans=first;
       ans->next=merge(ans->next,second);
   }
   else{
       ans=second;
       ans->next=merge(first,second->next);
   }
   return ans;
}

void mergeSort(Node** head){
   Node* head1=*head;
   if(head1 == NULL || head1->next==NULL){
       return;
   }
 Node* slow=head1;
Node* fast=head1->next;
while(fast != NULL && fast->next !=NULL){
    slow=slow->next;
    fast=fast->next->next;
}
   Node* first=head1;
   Node* second=slow->next;
   slow->next=NULL;
   mergeSort(&first);
   mergeSort(&second);
   *head=merge(first,second);
}

struct Node *sortDoubly(struct Node *head)
{
// Your code here
mergeSort(&head);
Node* temp=head;
//return temp;
temp->prev=NULL;
while(temp != NULL){
    if(temp->next !=NULL)
    temp->next->prev=temp;
    temp=temp->next;
}
return head;
}
// { Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}
  // } Driver Code Ends