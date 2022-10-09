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
    void findInor(TreeNode* root, vector<int> &ans){
        if(!root){
            return;
        }
        findInor(root->left, ans);
        ans.push_back(root->val);
        findInor(root->right,ans);
    } 
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> inor;
        findInor(root,inor);
        
        int low=0, high=inor.size()-1;
        while(low<high){
            if(inor[low]+inor[high]==k){
                return true;
            }
            if(inor[low]+inor[high]>k){
                high--;
            }
            else{
                low++;
            }
        }
        return false;
    }
};