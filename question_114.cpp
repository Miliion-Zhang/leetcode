/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        preorderFlatten( root );    
    }
    
    TreeNode *preorderFlatten(TreeNode *root){
        if(root == NULL)
            return NULL;
        
        TreeNode *leftLast = preorderFlatten( root->left );
        TreeNode *rightLast = preorderFlatten( root->right );
        if( leftLast != NULL ){
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = NULL;
            if( rightLast != NULL )
                leftLast->right = right;
        }
        
        if( rightLast != NULL )
            return rightLast;
        else if( leftLast != NULL )
            return leftLast;
        else
            return root;
    }
};