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
     TreeNode* addOneRow(TreeNode* root, int val, int depth) {  
        if(depth==1){
            TreeNode* ptr=new TreeNode(val,root,NULL);
            return ptr;
        }
        
        int d=2;
        queue<TreeNode*>q;
        q.push(root);
        
        while(d!=depth){
            int n=q.size();
            
            for(int i=0;i<n;i++){
                auto ele=q.front();
                q.pop();
                
                if(ele->left)q.push(ele->left);
                if(ele->right)q.push(ele->right);
            }
            
            d++;
        }
        
        while(!q.empty()){
            auto ele=q.front();
            q.pop();
            
            TreeNode* ptr=new TreeNode(val);
            TreeNode* ptr1=new TreeNode(val);
            
            ptr->left=ele->left;
            ele->left=ptr;
            
            ptr1->right=ele->right;
            ele->right=ptr1;
        }
        
        return root;
        
    }
};