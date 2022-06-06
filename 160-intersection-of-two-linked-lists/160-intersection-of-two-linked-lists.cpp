/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void changeSign(struct ListNode *head){
	while ( head )
	{
		head->val *= -1;
		head = head->next;
	}
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       changeSign( headA );
		
	while ( headB )
	{
		if ( headB->val < 0 ) break;
		headB = headB->next;
	}
		
	changeSign( headA );
	return headB; 
    }
};