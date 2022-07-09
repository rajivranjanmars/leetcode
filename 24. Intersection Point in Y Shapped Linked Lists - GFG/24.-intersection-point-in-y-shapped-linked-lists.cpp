// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
     // Your Code Here
    Node* curr1 = head1;
    Node* curr2 = head2;
    //Storing last nodes of two linked list
    while(curr1->next) curr1 = curr1->next;
    while(curr2->next) curr2 = curr2->next;

    //Finding size of first linked list
    Node* curr = head1;
    int size1 = 0;
    while(curr){
        size1++;
        curr = curr->next;
    }
    //Making all the nodes of 2nd linked list point to NULL
    curr = head2;
    while(curr){
        Node* temp = curr->next;
        curr->next = NULL;
        curr = temp;
    }
    //Stopping when a node is pointing to NULL
    curr = head1;
    int size = 1;
    while(curr->next){
        size++;
        curr = curr->next;
    }
    //Comparing size to check if that was the last node
    if(size==size1) 
    {
        //If that was last node of both the linked list
        if(curr1 == curr2) return curr1->data;
        else return -1; //else
    }
    else return curr->data; 
}

