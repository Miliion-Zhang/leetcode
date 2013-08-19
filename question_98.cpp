/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <limits.h>

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if( !root )
            return true;
                
        return isValidBST( root->left, root->val, INT_MIN ) && isValidBST( root->right, INT_MAX, root->val );
        
    }
    
    
    bool isValidBST(TreeNode *root, int upper, int bottom){
        if( !root )
            return true;
        
        if( root->val <= bottom || root->val >= upper )
            return false;
        
        return isValidBST( root->left, root->val, bottom ) && isValidBST( root->right, upper, root->val );
    }
};
