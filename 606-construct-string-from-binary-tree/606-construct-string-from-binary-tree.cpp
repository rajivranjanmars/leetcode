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
    string helper(TreeNode* root){
        if(!root)   return "()";
        
        string left  = helper(root->left);
        string right = helper(root->right);
        
        if(left=="()" && right=="()")      //  if is leaf node , then return the elements in brackets
            return "(" + to_string(root->val) + ")";
        
        if(right!="()")      // if right not empty , we need to add both left and right elements
            return "(" + to_string(root->val) +left + right + ")";
        else                   // but if right empty , we need to add left element only
            return "(" + to_string(root->val) +left + ")";
    }
    
    string tree2str(TreeNode* root) {
        string ans=helper(root);
        int len = ans.length();
        return ans.substr(1,len-2);      // to remove starting and ending brackets
    }
};
