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
    
    
    vector<double> ans;  //will hold the sum of values at particular level
    vector<int> vals; //will hold count of values on particular level
    
    void solve(TreeNode* root,int level=0) {
        if(!root)
            return;
        
        if(ans.size()==level) {   //if  size of our vector < current level then push_back any value, let it be 0
            ans.push_back(0);
            vals.push_back(0);
        }
        
        ans[level]+=root->val;   //add root->value to vector value at index == level
        vals[level]++;   //increase count of values at that level
        
        solve(root->left,level+1);
        solve(root->right,level+1);
        
    }

    vector<double> averageOfLevels(TreeNode* root) {
        solve(root);
        for(int i=0;i<ans.size();i++)
            ans[i]=ans[i]/vals[i];         //take average 
        return ans;
    }
};