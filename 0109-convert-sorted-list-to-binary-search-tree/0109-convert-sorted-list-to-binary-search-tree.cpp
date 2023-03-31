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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode* sListToBST(ListNode* &list, int start, int end) {
    if (start > end) return NULL;
    
    int mid = (end + start)>>1;
    TreeNode *leftCh = sListToBST(list, start, mid - 1);
    TreeNode *parent = new TreeNode(list->val);
    parent->left = leftCh;
    list = list->next;
    parent->right = sListToBST(list, mid + 1, end);
    
    return parent;
  }
  
  TreeNode* sortedListToBST(ListNode* head) {
    int n = 0;
    ListNode *hh = head;
    
    while(hh) n++, hh = hh->next;
        
    return sListToBST(head, 0, n - 1);       
  }
};