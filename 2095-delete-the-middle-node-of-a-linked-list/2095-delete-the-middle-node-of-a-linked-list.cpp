/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
			return NULL;
		}
		ListNode* temp=head;
		int len=1;
		while(temp->next!=NULL){
			len++;
			temp=temp->next;
		}
		temp=head;
		for(int i=1;i<len/2 && temp->next!=NULL;i++){
			temp=temp->next; 
		}
		ListNode* cur = temp->next;
		temp->next=cur->next;
		delete(cur);
		return head;
    }
};