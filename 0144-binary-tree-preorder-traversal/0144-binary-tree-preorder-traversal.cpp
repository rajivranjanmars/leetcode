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
   vector<int> v;
 vector<int> preorder(TreeNode* root){ 
    
     // Base case
     if(root==NULL){
            return v;
        }
     v.push_back(root->val); // Node value is stored in the vector.
     preorder(root->left); // Then Traverse Left child of tree ( Left subtree)
     preorder(root->right); // Then handle right child of tree ( Right sub tree.)
     return v;
 }
public:
    vector<int> preorderTraversal(TreeNode* root) {
    v = preorder(root);
    return v;
    }
};